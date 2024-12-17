/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:35 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/16 16:09:27 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	r;
	int	sign;
	int	i;

	i = 0;
	r = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] == <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r  * sign);
}

void	init_stack(t_box **a, char *av[], bool flag)
{
	long	nb;
	int	i;

	i = 0;
	while (av[i])
	{
		if (check_syntax(av[i]))
		{
			ft_error(a, av, flag);
		}
		if (nb > INT_MAX || nb < INT_MIN)
		{
			ft_error(a, av, flag);
		}
		if (repetition(*a, (int)nb))
		{
			ft_error(a, av, flag);
		}
		append_node(a, (int)nbr);
		i++;
	}
	if (flag)
		free_split(av);
}
