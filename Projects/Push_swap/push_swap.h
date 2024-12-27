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

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_box
{
	int 		nb;           /* valor do numero */
	int 		position;     /* posicao do valor */	
	int 		moves;	      /* quantos moves precisa para ir ao sito */
	int		push_price;    /* quantos moves precisa para ir ao sitio correcto */
	bool		above_median; /* acima ou abaixo do mediana? */
	bool		cheapest;     /* mais baratos em termos de moves? */
	struct	s_box	*target_node; /* node que vamos trabalhar */
	struct  s_box   *next;	      /* pointer para a proxima s_box */
	struct  s_box   *previous;    /* pointer para a s_box anterior */	
}			t_box;

//** Para gerir argumentos : " 1 15 93 " **//

char	**split(char *str, char sep);   // ft_split

//** para gerar mensagens de erro e gerir erros **//

void	ft_error(t_box **a, char *av[], bool flag); //error_free 
void	free_split(char *av[]); // free matrix 
void	clear_stack(t_box **stack); // free_stack
int	repetition(t_box *a, int nbr); // error_repetition
int	check_syntax(char *str_nb); // error_syntax

//** para inicar o stack **//

void	init_stack(t_box **a, char *av[], bool flag_ac_2); //stack_init
void	start_position(t_box *stack); // set_current_position
void	define_cheapest(t_box *b); //set_cheapest 
void	set_price(t_box *a, t_box *b); // set_price
void	start_boxes(t_box *a, t_box *b); // init_nodes

//** linked lists utils **//

t_box	*cheapest(t_box *stack);  //return cheapest
t_box	*smallest_box(t_box *stack); // find_smallest
t_box	*last_node(t_box *list);  //find_last_node
void	join_box(t_box **stack, int nbr);  // append_node
void	finish_rotation(t_box **stack, t_box *tob_box, char stack_name);
int	stack_size(t_box *stack); // stack_len
bool	stack_sort(t_box *stack);  // 


//** Algoritmos **//

void	three_sort(t_box **a); // tiny_sort
void	five_sort(t_box **a, t_box **b); // handle_five
void	push_swap(t_box **a, t_box **b);

//** Commands **//

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
