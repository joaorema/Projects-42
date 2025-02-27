/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:55 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/27 14:46:54 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_nb(t_table *table, char *av[])
{
	table->nbr_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1000;
	table->time_to_eat = ft_atol(av[3]) * 1000;
	table->time_to_sleep = ft_atol(av[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		error_exit("Timestamp should be bigger than 60miliseconds!");
	if (av[5])
		table->max_meals = ft_atol(av[5]);
}

const char	*valid_nb(const char *str)
{
	int			len;
	const char	*nb;
	int			i;

	i = 0;
	len = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		error_exit("Error. Program only take positive numbers!\n");
	nb = str;
	while (is_number(str[i++]))
		len++;
	if (len > 10)
		error_exit("Error. The number is to big / int_max is the limit!");
	return (nb);
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	str = valid_nb(str);
	while (is_number(*str))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (nb > INT_MAX)
		error_exit("Error. The number is to big / int_max is the limit!");
	return (nb);
}

void	wait_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_ready))
		;
}

void	fair(t_philo *philo)
{
	if (philo->table->nbr_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
		{
			precise_usleep(30000, philo->table);
		}
	}
	else
	{
		if (philo->id % 2)
		{
			thinking(philo, true);
		}
	}
}
