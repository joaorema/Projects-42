/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:16:33 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/27 10:23:16 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_box **dest, t_box **src)
{
	t_box	*box_to_push;

	if (*src == NULL)
		return ;
	box_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	box_to_push->previous = NULL;
	if (*dest == NULL)
	{
		*dest = box_to_push;
		box_to_push->next = NULL;
	}
	else
	{
		box_to_push->next = *dest;
		box_to_push->next->previous = box_to_push;
		*dest = box_to_push;
	}
}

void	pa(t_box **a, t_box **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_box **b, t_box **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
