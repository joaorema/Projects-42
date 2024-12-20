/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:13:39 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/17 13:53:28 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_position(t_box *stack)
{
	int	i;
	int	line;

	i = 0;
	if(stack == NULL)
		return ;
	line = stack_size(stack) / 2;  //para chegar a box do meio //
	while(stack)
	{
		stack->position = i;
		if(i <= line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	find_target_box(t_box *a, t_box *b)
{
	t_box	*current_a;
	t_box	*target_box;
	long		best_match;
	
	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while(current_a)
		{
			if(current_a->nb > b->nb
					&& current_a->nb < best_match)
			{
				best_match = current_a->nb;
				target_box = current_a;
			}
			current_a = current_a->next;
		}
		if(best_match == LONG_MAX)
			b->target_node = smallest_box(a);
		else
			b->target_node = target_box;
		b = b->next;
	}
}

void	define_cheapest(t_box *b)
{
	long		best_match;
	t_box	*best_match_box;

	if(b == NULL)
		return;
	best_match = LONG_MAX;
	while(b)
	{
		if(b->push_price < best_match)
		{
			best_match = b->push_price;
			best_match_box = b;
		}
		b = b->next;
	}
	best_match_box->cheapest = true;
}

void	set_price(t_box *a, t_box *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);

	while(b)
	{
		b->push_price = b->position;
		if(!(b->above_median))
			b->push_price = size_b - (b->position);
		if(b->target_node->above_median)
			b->push_price += b->target_node->position;
		else
			b->push_price += size_a - (b->target_node->position);
		b = b->next;
	}
}

void	start_boxes(t_box *a, t_box *b)
{
	start_position(a);
	start_position(b);
	find_target_box(a, b);
	set_price(a, b);
	define_cheapest(b);
}
			
	
