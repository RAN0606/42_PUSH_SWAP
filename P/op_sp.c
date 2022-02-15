/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:00:47 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 18:02:26 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void pb(t_stack *stack, int act, int p)
{
	if (act && stack->atop < stack->size)
		stack->atop += 1;
	if (p)
		write(1,"pb\n", 3);
}

void pa(t_stack *stack,int act, int p)
{
	if (act && stack->atop > 0)
		stack->atop -= 1;
	if (p)
		write(1,"pa\n", 3);

}

void sa(t_stack *stack,int act, int p)
{
	int temp;

	if (act && stack->atop < stack->size-1)
	{	
		temp = stack->ab[stack->atop];
		stack->ab[stack->atop] = stack->ab[ stack->atop + 1];
		stack->ab[stack->atop + 1] = temp;
	}
	if (p)
		write(1,"sa\n", 3);
}

void sb(t_stack *stack,int act, int p)
{
	int temp;

	if (act && stack->atop > 1)
	{	
		temp = stack->ab[stack->atop - 1];
		stack->ab[stack->atop - 1] = stack->ab[ stack->atop - 2];
		stack->ab[stack->atop - 2] = temp;
	}
	if (p)
		write(1,"sb\n", 3);

}

void ss(t_stack *stack,int act, int p)
{
	if (act)
	{
		sa(stack,1,0);
		sb(stack,1,0);
	}
	if (p)
		write(1,"ss\n",3);
}
