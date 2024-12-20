/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:02 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/16 13:50:02 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_box	*a;
	t_box	*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		return (1);
	}
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
	}
	start_stack(&a, av + 1, ac == 2);
	if (!start_stack(a))
	{
		if (stack_size(a) == 2)
		{
			sa(&a, false);
		}
		else if (stack_size(a) == 3)
		{
			three_sort(&a);
		}
		else
		{
			push_swap(&a, &b);
		}
	}
	clear_stack(&a);
}
