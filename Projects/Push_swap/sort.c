/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:50:58 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/20 12:04:05 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sort(t_box *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_box	*f_highest(t_box *stack)
{
	int		highest;
	t_box	*highest_box;

	if (stack == NULL)
		return (0);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nb > highest)
		{
			highest = stack->nb;
			highest_box = stack;
		}
		stack = stack->next;
	}
	return (highest_box);
}

void	three_sort(t_box **a)
{
	t_box	*highest_node;

	highest_node = f_highest(*a);
	if (highest_node == *a)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		sa(a, false);
}

void	five_sort(t_box **a, t_box **b)
{
	while (stack_size(*a) > 3)
	{
		start_boxes(*a, *b);
		finish_rotation(a, smallest_box(*a), 'a');
		pb(b, a, false);
	}
}
