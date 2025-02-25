/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:27 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/25 12:30:21 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_dead(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = get_time(MILLISECOND)
		- get_long(&philo->philo_mutex, &philo->time_of_last_meal);
	t_to_die = philo->table->time_to_die / 1000;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	increment_long(t_mtx *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}

bool	check_threads(t_mtx *mutex, long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}

void	*check_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *) data;
	while (!check_threads(&table->table_mutex,
			&table->nbr_threads_running, table->nbr_philo))
		;
	while (!simulation_finish(table))
	{
		i = -1;
		while (++i < table->nbr_philo && !simulation_finish(table))
		{
			if (philo_dead(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_simulation, true);
				write_status(DIED, table->philos + i);
			}
		}
	}
	return (NULL);
}

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->nbr_philo)
	{
		philo = table->philos + i;
		safe_mutex(&philo->philo_mutex, DESTROY);
	}
	safe_mutex(&table->table_mutex, DESTROY);
	safe_mutex(&table->write_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
