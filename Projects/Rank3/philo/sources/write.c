/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:20:12 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/25 12:33:38 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if ((status == FIRST_FORK || status == SECOND_FORK)
		&& !simulation_finish(philo->table))
		printf("%-6ld %ld has taken a fork \n", elapsed, philo->id);
	else if (status == EATING && !simulation_finish(philo->table))
		printf("%-6ld %ld is a eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finish(philo->table))
		printf("%-6ld %ld is sleeping!\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finish(philo->table))
		printf("%-6ld %ld is thinking!\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld %ld is dead!\n", elapsed, philo->id);
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elasped;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finish(table))
			break ;
		elasped = get_time(MICROSECOND) - start;
		remaining = usec - elasped;
		if (remaining > 1000)
			usleep(remaining / 2);
		else
		{
			while (get_time(MICROSECOND) - start < usec)
				;
		}
	}
}
