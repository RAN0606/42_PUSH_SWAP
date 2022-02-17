/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:46:26 by rliu              #+#    #+#             */
/*   Updated: 2022/02/17 15:39:32 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

/***************creat stack**************************/

typedef struct stackswap
{
	int	*ab;
	int	*inial;
	int	*sort;
	int	atop;
	int	size;
}	t_stack;

/***********************Tools***************************/

int		check_args(int argc, char **argv);

void	stack_free(t_stack *stack);

/*******************Initiate stack**********************/

void	init_stack(t_stack *stack, int argc, char **argv);

/*****************Operations***************************/

void	pb(t_stack *stack, int act, int p);

void	pa(t_stack *stack, int act, int p);

void	sa(t_stack *stack, int act, int p);

void	sb(t_stack *stack, int act, int p);

void	ra(t_stack *stack, int act, int p);

void	rra(t_stack *stack, int act, int p);

void	rb(t_stack *stack, int act, int p);

void	rrb(t_stack *stack, int act, int p);

void	ss(t_stack *stack, int act, int p);

void	rr(t_stack *stack, int act, int p);

void	rrr(t_stack *stack, int act, int p);

/******************sort********************************/

//sort_utils
int		sort_check(t_stack *stack);

int		sort_checka(t_stack *stack);

void	tour_1(t_stack *stack, int x);

int		absolu(int x);

int		cont(int x, int y);

//sort_core
void	insert(t_stack *stack);

void	sort_1_3(t_stack *stack);

void	sort_1_6(t_stack *stack);

int		main(int argc, char **argv);

#endif
