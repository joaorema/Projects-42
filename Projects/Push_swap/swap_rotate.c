/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:32:21 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/20 12:42:32 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_box **stack)
{
	t_box	*last_box;
	int			len;

	len = stack_size(*stack);
	if(stack == NULL || *stack == NULL || len == 1)
		return ;
	last_box = last_node(*stack);
	last_box->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_box->next->previous = last_box;
	last_box->next->next = NULL;
}

void	ra(t_box **a, bool checker)
{
	rotate(a);
	if(!checker)
		write(1, "ra\n", 3);
}

void	rb(t_box **b, bool checker)
{
	rotate(b);
	if(!checker)
		write(1, "rb\n", 3);
}

void	rr(t_box **a, t_box **b, bool checker)
{
	rotate(a);
	rotate(b);
	if(!checker)
		write(1, "rr\n", 3);
}

