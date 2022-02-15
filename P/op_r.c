/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:02:52 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 18:03:51 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ra(t_stack *stack,int act, int p)
{
	int temp;
	int i;
	
	if (act && stack->atop < stack->size - 1)
	{
		i = stack->atop;
		temp = stack->ab[i];
		while(i < stack->size - 1)
		{
			stack->ab[i] = stack->ab[i + 1];
			i++;
		}
		stack->ab[i] = temp;
	}
	if (p)
		write(1,"ra\n", 3);
	return ;
}

void rb(t_stack *stack,int act, int p)
{
	int temp;
	int i;

	if (act && stack->atop > 1)
	{
		i = stack->atop - 1;
		temp = stack->ab[i];
		while(i > 0)
		{
			stack->ab[i] = stack->ab[i-1];
			i--;
		}
		stack->ab[i] = temp;
	}
	if (p)
		write(1,"rb\n", 3);
}

void rr(t_stack *stack,int act, int p)
{
	if (act)
	{
		ra(stack,1,0);
		rb(stack,1,0);
	}
	if (p)
		write(1,"rr\n",3);
}

