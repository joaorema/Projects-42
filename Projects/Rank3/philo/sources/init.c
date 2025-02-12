#include "../include/philo.h"

void    init_data(t_table *table)
{
    int i;

    i = -1;
    table->end_simulation = false;
    table->threads_ready = false;
    table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo);   ///malloc for the array of philos
    safe_mutex(&table->table_mutex, INIT);
    safe_mutex(&table->write_mutex, INIT);
    table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo);     //malloc for the array of forks 
    while(++i < table->nbr_philo)
    {
        safe_mutex(&table->forks[i].fork, INIT);
        table->forks[i].id_fork = i;  //sets the id for each fork
    }
    philo_init(table);

}

static void give_forks(t_philo *philo, t_fork *forks, int index)
{
    int nbr_philos;

    nbr_philos = philo->table->nbr_philo;    //how many philos exist
    if(!philo->id % 2 == 0)
    {
        philo->first_fork = &forks[(index + 1) % nbr_philos];  //when philo id is odd
        philo->second_fork = &forks[index];
    }     
    if(philo->id % 2 == 0) // when philo id is even;
    {
        philo->first_fork = &forks[index];       //philo_id - 1 = philo 5 get fork nb 4
        philo->second_fork = &forks[(index + 1) % nbr_philos];   //philo position + 1 % nbr de philos
    }

}

void    philo_init(t_table *table)
{
    int i;
    t_philo *philo;

    i = -1;
    while(++i < table->nbr_philo)
    {
        philo = table->philos + i;   /// set number for each philo created
        philo->id = i + 1;
        philo->full = false;
        philo->counter = 0;
        philo->table = table;
        safe_mutex(&philo->philo_mutex, INIT);
        give_forks(philo, table->forks, i);
    }
    
}
