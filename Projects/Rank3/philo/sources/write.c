#include "../include/philo.h"

static void write_status_debugg(t_philo_status status, t_philo *philo, long elapsed)
{
    if (status == FIRST_FORK && !simulation_finish(philo->table))
        printf("%-6ld %ld has taken the first fork 🍴 fork id:[🍴 %ld 🍴]\n", elapsed, philo->id, philo->first_fork->id_fork);
    else if (status == SECOND_FORK && !simulation_finish(philo->table))
        printf("%-6ld %ld has taken the second fork 🍴 fork id :[🍴 %ld 🍴]\n", elapsed, philo->id, philo->second_fork->id_fork);
    else if (status == EATING && !simulation_finish(philo->table))
        printf("%-6ld %ld is a eating 🍲 meal nbr :[🍲 %ld 🍲]\n", elapsed, philo->id, philo->counter);
    else if (status == SLEEPING && !simulation_finish(philo->table))
        printf("%-6ld %ld is sleeping 😴😴!\n", elapsed, philo->id);
    else if (status == THINKING && !simulation_finish(philo->table))
        printf("%-6ld %ld is thinking 🤔🤔!\n", elapsed, philo->id);
    else if (status == DIED)
        printf("%-6ld %ld is dead 💀💀!\n", elapsed, philo->id);
}

void write_status(t_philo_status status, t_philo *philo, bool debug)
{
    long elapsed;

    elapsed = get_time(MILLISECOND) - philo->table->start_simulation; // get the time since - time since evaluation started

    if (philo->full)
        return;
    safe_mutex(&philo->table->write_mutex, LOCK);
    if(debug)
        write_status_debugg(status, philo, elapsed);
    else
    {
        if ((status == FIRST_FORK || status == SECOND_FORK) && !simulation_finish(philo->table))
            printf("%-6ld %ld has taken a fork \n", elapsed, philo->id);
        else if (status == EATING && !simulation_finish(philo->table))
            printf("%-6ld %ld is a eating\n", elapsed, philo->id);
        else if (status == SLEEPING && !simulation_finish(philo->table))
            printf("%-6ld %ld is sleeping!\n", elapsed, philo->id);
        else if (status == THINKING && !simulation_finish(philo->table))
            printf("%-6ld %ld is thinking!\n", elapsed, philo->id);
        else if (status == DIED)
            printf("%-6ld %ld is dead!\n", elapsed, philo->id);
    }
    safe_mutex(&philo->table->write_mutex, UNLOCK);
}

