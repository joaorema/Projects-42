#include "../include/philo.h"

void    write_status(t_philo_status status, t_philo *philo)
{
    long elapsed;

    elapsed = get_time(MILLISECOND) - philo->table->start_simulation;  //get the time since - time since evaluation started

    if(philo->full)
        return;
    safe_mutex(&philo->table->write_mutex, LOCK);
    if((status == FIRST_FORK || status == SECOND ) && !simulation_finish(philo->table))
         printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
    else if(status == EATING  && !simulation_finish(philo->table))
        printf("%-6ld %d is a eating\n", elapsed, philo->id);
    else if(status == SLEEPING && !simulation_finish(philo->table))
        printf("%-6ld %d is sleeping!\n", elapsed, philo->id);
    else if(status == THINKING && !simulation_finish(philo->table))
        printf("%-6ld %d is thinking!\n", elapsed, philo->id);
    else if(status == DIED)
        printf("%-6ld %d is dead!\n", elapsed, philo->id);
    safe_mutex(&philo->table->write_mutex, UNLOCK);
}
