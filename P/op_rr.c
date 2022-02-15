/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:04:09 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 18:04:53 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *stack,int act, int p)
{
	int	temp;
	int i;

	if (act && stack->atop < stack->size - 1)
	{
		i = stack->size - 1;
		temp = stack->ab[stack->size - 1];
		while (i > stack->atop)
		{
			stack->ab[i] = stack->ab[i-1];
			i--;
		}
		stack->ab[i] = temp;
	}
	if (p)
		write(1,"rra\n", 4);
}

void rrb(t_stack *stack,int act, int p)
{
	int temp;
	int	i;
	
	if (stack->atop > 1)
	{
		i = 0;
		temp = stack->ab[i];
		while (i < stack->atop - 1)
		{
			stack->ab[i] = stack->ab[i + 1];
			i++;
		}
		stack->ab[i] = temp;
	}
	if (p)
		write(1,"rrb\n", 4);
}

void rrr(t_stack *stack, int act , int p)
{
	if (act)
	{
		rra(stack,1,0);
		rrb(stack,1,0);
	}
	if (p)
		write(1,"rrr\n",4);
}
