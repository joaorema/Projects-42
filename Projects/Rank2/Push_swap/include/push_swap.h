/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:20:40 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/16 11:22:36 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_box
{
	int				nb;
	int				position;	
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_box	*target_node;
	struct s_box	*next;
	struct s_box	*previous;
}			t_box;

char	**split(char *str, char sep);

void	ft_error(t_box **a, char *av[], bool flag);
void	free_split(char *av[]);
void	clear_stack(t_box **stack);
int		repetition(t_box *a, int nbr);
int		check_syntax(char *str_nb);

void	init_stack(t_box **a, char *av[], bool flag_ac_2);
void	start_position(t_box *stack);
void	define_cheapest(t_box *b);
void	set_price(t_box *a, t_box *b);
void	start_boxes(t_box *a, t_box *b);

t_box	*cheapest(t_box *stack);
t_box	*smallest_box(t_box *stack);
t_box	*last_node(t_box *list);
void	join_box(t_box **stack, int nbr);
void	finish_rotation(t_box **stack, t_box *tob_box, char stack_name);
int		stack_size(t_box *stack);
bool	stack_sort(t_box *stack);

void	three_sort(t_box **a);
void	five_sort(t_box **a, t_box **b);
void	push_swap(t_box **a, t_box **b);

void	sa(t_box **a, bool checker);
void	sb(t_box **b, bool checker);
void	ss(t_box **a, t_box **b, bool checker);
void	ra(t_box **a, bool checker);
void	rb(t_box **b, bool checker);
void	rr(t_box **a, t_box **b, bool checker);
void	rra(t_box **a, bool checker);
void	rrb(t_box **b, bool checker);
void	rrr(t_box **a, t_box **b, bool checker);
void	pa(t_box **a, t_box **b, bool checker);
void	pb(t_box **b, t_box **a, bool checker);

#endif
