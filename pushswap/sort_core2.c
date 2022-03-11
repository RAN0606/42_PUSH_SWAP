/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_core2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:45:46 by rliu              #+#    #+#             */
/*   Updated: 2022/02/21 16:49:22 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_insertsigle(int a, int b, t_stack *stack)
{
	while (a > 0)
	{
		ra(stack, 1, 1);
		a--;
	}
	while (a < 0)
	{
		rra(stack, 1, 1);
		a++;
	}
	while (b > 0)
	{
		rb(stack, 1, 1);
		b--;
	}
	while (b < 0)
	{
		rrb(stack, 1, 1);
		b++;
	}
}

void	pre_insertdouble(int a, int b, t_stack *stack)
{
	while (a > 0 && b > 0)
	{
		rr(stack, 1, 1);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		rrr(stack, 1, 1);
		a++;
		b++;
	}
	pre_insertsigle(a, b, stack);
}

int	insert_getindex(t_stack *stack, int i)
{
	int	x;

	x = 0;
	if (stack->ab[i] > stack->ab[stack->atop])
	{
		x = stack->atop;
		while (x < stack->size && stack->ab[i] > stack->ab[x])
		{
			x++;
			if (x < stack->size && stack->ab[x] < stack->ab[x - 1])
				return (x);
		}
	}
	else
	{
		x = stack->size;
		while (stack->ab[i] < stack->ab[x - 1] && x > stack->atop)
		{
			x--;
			if (x > stack->atop && stack->ab[x - 1] > stack->ab[x])
				return (x);
		}
	}
	return (x);
}

void	insert_postab(t_stack *stack, int *pos, int indexa, int indexb)
{
	int	stepa;
	int	stepb;
	int	steptotal;

	steptotal = -1;
	if (indexa - stack->atop <= (stack->size - stack->atop) / 2)
		stepa = indexa - stack->atop;
	else
		stepa = indexa - stack->size;
	if (indexb >= stack->atop / 2)
		stepb = stack->atop - 1 - indexb;
	else
		stepb = -(indexb + 1);
	steptotal = cont(stepa, stepb);
	if ((steptotal < pos[2] && steptotal >= 0) || indexb == stack->atop - 1)
	{	
		pos[0] = stepa;
		pos[1] = stepb;
		pos[2] = steptotal;
	}
}

void	insert(t_stack *stack)
{
	int	pos[3];
	int	indexb;
	int	indexa;

	pos[2] = -1;
	pos[0] = 0;
	pos[1] = 0;
	indexb = stack->atop - 1;
	while (indexb >= 0)
	{
		indexa = insert_getindex(stack, indexb);
		insert_postab(stack, pos, indexa, indexb);
		if (pos[2] == 0 || pos[2] == 1)
			break ;
		indexb--;
	}
	pre_insertdouble(pos[0], pos[1], stack);
	pa(stack, 1, 1);
}
