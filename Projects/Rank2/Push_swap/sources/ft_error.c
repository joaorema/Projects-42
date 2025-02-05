/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:44 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/17 10:53:13 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char *av[])
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	clear_stack(t_box **stack)
{
	t_box	*temp;
	t_box	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_error(t_box **a, char *av[], bool flag_ac_2)
{
	clear_stack(a);
	if (flag_ac_2)
	{
		free_split(av);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	repetition(t_box *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nb == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_syntax(char *str_nb)
{
	int		i;
	char	*str;

	i = 0;
	str = str_nb;
	if (!(str[i] == '+'
			|| str[i] == '-'
			|| (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i++])
	{
		if (!(str[i] >= '0' || str[i] <= '9'))
		{
			return (1);
		}
	}
	return (0);
}
