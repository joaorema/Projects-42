#include "../include/philo.h"


static void eat(t_philo *philo)
{
    safe_mutex(&philo->first_fork->fork, LOCK);
    write_status(FIRST_FORK, philo);
    safe_mutex(&philo->second_fork->fork, LOCK);
    write_status(SECOND_FORK, philo);
    set_long(&philo->philo_mutex, &philo->time_of_last_meal, get_time(MILLISECOND));  //INSERT INTO TIME_OF_LAST_MEAL THE TIME SINCE LAST MEAL.
    philo->counter++;
    write_status(EATING, philo);
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
    wait_threads(philo->table);            //while table->threads_ready false wait for other threads. spinlock  
    while(!simulation_finish(philo->table))
    {
        if(philo->full)
            break;
        eat(philo);    /// eat
        write_status(SLEEPING, philo);   // 
        precise_usleep(philo->table->time_to_sleep, philo->table);
        thinking(philo);
    } 
    return 0;      
}


void    start_dinner(t_table *table)
{
    int i;

    i = -1;
    if(table->nbr_philo == 0)   //when nbr of meals == 0 av[5] == 0
        return ;
    /*else if(table->nbr_philo == 1)  //when we just have 1 philo.
        handle_one(); // still need to make it */
    else
    {
        while(++i < table->nbr_philo)
        {
            safe_thread(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE);
        }
    }
    set_bool(&table->table_mutex, &table->threads_ready, true);  // alterar o bool threads_ready to true;
    table->start_simulation = get_time(MILLISECOND);
}

void    wait_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->threads_ready));  //while table->threads_ready false wait for other threads. spinlock
}

void    thinking(t_philo *philo)
{
    write_status(THINKING, philo);
}