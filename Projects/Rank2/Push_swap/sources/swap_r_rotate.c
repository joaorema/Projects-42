/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:58:14 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/27 11:02:56 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_box **stack)
{
	t_box	*last;
	int		len;

	len = stack_size(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = last_node(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}

void	rra(t_box **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_box **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_box **a, t_box **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
