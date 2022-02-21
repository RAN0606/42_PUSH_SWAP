/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_core2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:45:46 by rliu              #+#    #+#             */
/*   Updated: 2022/02/16 16:58:38 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pre_insertsigle(int x, int y, t_stack *stack)
{
	while (x > 0)
	{
		ra(stack, 1, 1);
		x--;
	}
	while (x < 0)
	{
		rra(stack, 1, 1);
		x++;
	}
	while (y > 0)
	{
		rb(stack, 1, 1);
		y--;
	}
	while (y < 0)
	{
		rrb(stack, 1, 1);
		y++;
	}
}

static void	pre_insertdouble(int x, int y, t_stack *stack)
{
	while (x > 0 && y > 0)
	{
		rr(stack, 1, 1);
		x--;
		y--;
	}
	while (x < 0 && y < 0)
	{
		rrr(stack, 1, 1);
		x++;
		y++;
	}
	pre_insertsigle(x, y, stack);
}

static int	insert_getindex(t_stack *stack, int i)
{
	int	x;

	x = stack->atop;
	if (stack->ab[i] > stack->ab[stack->atop])
	{
		while (stack->ab[i] > stack->ab[x] && x < stack->size)
		{
			x++;
			if (stack->ab[x] < stack->ab[x - 1] && x < stack->size)
				return (x);
		}
	}
	else
	{
		x = stack->size;
		while (stack->ab[i] < stack->ab[x - 1] && x > stack->atop)
		{
			x--;
			if (stack->ab[x - 1] > stack->ab[x] && x > stack->atop)
				return (x);
		}
	}
	return (x);
}

static void	insert_postab(t_stack *stack, int *pos, int indexa, int indexb)
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
