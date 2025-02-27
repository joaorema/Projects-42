/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:58 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/27 15:23:08 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_table	table;
	int		i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			check_number(av[i]);
			i++;
		}
		parse_nb(&table, av);
		init_data(&table);
		start_dinner(&table);
		clean(&table);
		return (0);
	}
	else
		error_exit("Invalid nbr of arguments!");
	return (0);
}
