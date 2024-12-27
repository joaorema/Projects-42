/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:43 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/17 11:25:43 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*last_node(t_box *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	join_box(t_box **stack, int nbr)
{
	t_box	*box;
	t_box	*last_box;

	if (stack == NULL)
		return ;
	box = malloc(sizeof(t_box));
	if (!box)
		return ;
	box->next = NULL;
	box->nb = nbr;
	if (!*stack)
	{
		*stack = box;
		box->previous = NULL;
	}
	else
	{
		last_box = last_node(*stack);
		last_box->next = box;
		box->previous = last_box;
	}
}

int	stack_size(t_box *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

t_box	*smallest_box(t_box *stack)
{
	long	smallest;
	t_box	*smallest_box;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nb < smallest)
		{
			smallest = stack->nb;
			smallest_box = stack;
		}
		stack = stack->next;
	}
	return (smallest_box);
}

t_box	*cheapest(t_box *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
