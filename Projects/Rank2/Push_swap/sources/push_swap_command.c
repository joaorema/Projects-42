/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:25:53 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/27 10:52:06 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_both(t_box **a, t_box **b, t_box *cheapest_box)
{
	while (*a != cheapest_box->target_node && *b != cheapest_box)
		rr(a, b, false);
	start_position(*a);
	start_position(*b);
}

static void	reverse_rotate_both(t_box **a, t_box **b, t_box *cheapest_box)
{
	while (*a != cheapest_box->target_node && *b != cheapest_box)
		rrr(a, b, false);
	start_position(*a);
	start_position(*b);
}

void	finish_rotation(t_box **stack, t_box *top_box, char stack_name)
{
	while (*stack != top_box)
	{
		if (stack_name == 'a')
		{
			if (top_box->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_box->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_boxes(t_box **a, t_box **b)
{
	t_box	*cheapest_box;

	cheapest_box = cheapest(*b);
	if (cheapest_box->above_median && cheapest_box->target_node->above_median)
		rotate_both(a, b, cheapest_box);
	else if (!(cheapest_box->above_median)
		&& !(cheapest_box->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_box);
	finish_rotation(b, cheapest_box, 'b');
	finish_rotation(a, cheapest_box->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_box **a, t_box **b)
{
	t_box	*smallest;
	int		len_a;

	len_a = stack_size(*a);
	if (len_a == 5)
		five_sort(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	three_sort(a);
	while (*b)
	{
		start_boxes(*a, *b);
		move_boxes(a, b);
	}
	start_position(*a);
	smallest = smallest_box(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
