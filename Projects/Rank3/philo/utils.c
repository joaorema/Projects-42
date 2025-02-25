/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:20:08 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/25 12:20:09 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(const char *error)
{
	printf(RED"%s\n"RESET, error);
	exit(EXIT_FAILURE);
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error with MAlloc!");
	return (ret);
}

long	get_time(t_time_code time_code)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		error_exit("Failed gettimeofday!");
	if (time_code == SECOND)
		return (time.tv_sec + (time.tv_usec / 1000000));
	else if (time_code == MILLISECOND)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((time.tv_sec * 1000000) + time.tv_usec);
	else
		error_exit("Wrong input to gettime!");
	return (69);
}
