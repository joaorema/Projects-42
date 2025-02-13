#include "../include/philo.h"


static void eat(t_philo *philo)
{
    safe_mutex(&philo->first_fork->fork, LOCK);
    write_status(FIRST_FORK, philo, true);
    safe_mutex(&philo->second_fork->fork, LOCK);
    write_status(SECOND_FORK, philo, true);
    set_long(&philo->philo_mutex, &philo->time_of_last_meal, get_time(MILLISECOND));  //INSERT INTO TIME_OF_LAST_MEAL THE TIME SINCE LAST MEAL.
    philo->counter++;
    write_status(EATING, philo, true);
    precise_usleep(philo->table->time_to_eat, philo->table);   /// sleep nbr defined in the av/ac 
    if(philo->table->max_meals > 0 && philo->counter == philo->table->max_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);     //if nbr of max_meals > 0 and counter of meals == max_number of meals set bool to true
    safe_mutex(&philo->first_fork->fork, UNLOCK);
    safe_mutex(&philo->second_fork->fork, UNLOCK);
}

void    *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_threads(philo->table);          //while table->threads_ready false wait for other threads. spinlock 
    set_long(&philo->philo_mutex, &philo->time_of_last_meal, get_time(MILLISECOND));
    increment_long(&philo->table->table_mutex, &philo->table->nbr_threads_running); 
    while(!simulation_finish(philo->table))
    {
        if(philo->full)
            break;
        eat(philo);    /// eat
        set_long(&philo->philo_mutex, &philo->time_of_last_meal, get_time(MILLISECOND));
        write_status(SLEEPING, philo, true);   // 
        precise_usleep(philo->table->time_to_sleep, philo->table);
        thinking(philo);
    } 
    return 0;      
}


void    start_dinner(t_table *table)
{
    int i;

    i = -1;
    if(table->max_meals == 0)   //when nbr of meals == 0 av[5] == 0
        return ;
    else if(table->nbr_philo == 1)
        safe_thread(&table->philos[0].thread_id, solo_philo, &table->philos[0], CREATE);
    else
    {
        while(++i < table->nbr_philo)
        {
            safe_thread(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE);
        }
    }
    safe_thread(&table->monitor, check_dinner, table, CREATE);
    table->start_simulation = get_time(MILLISECOND);
    set_bool(&table->table_mutex, &table->threads_ready, true);
    i = -1;
    while(++i < table->nbr_philo)
    {
        safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
    }
   
}

void    wait_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->threads_ready));  //while table->threads_ready false wait for other threads. spinlock
}

void    thinking(t_philo *philo)
{
    write_status(THINKING, philo, true);
}

void    *solo_philo(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;

    wait_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->time_of_last_meal, get_time(MILLISECOND));
    increment_long(&philo->philo_mutex, &philo->table->nbr_threads_running);
    write_status(FIRST_FORK, philo, true);
    while(!simulation_finish(philo->table))
    {
        usleep(2000);
    }
    return NULL;
}
