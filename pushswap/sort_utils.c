/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:55:54 by rliu              #+#    #+#             */
/*   Updated: 2022/02/16 15:13:48 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->atop == 0)
	{	
		while (i < stack->size - 1)
		{
			if (stack->ab[i] > stack->ab[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	sort_checka(t_stack *stack)
{	
	int	i;

	i = stack->atop;
	while (i < stack->size - 1)
	{
		if (stack->ab[i] > stack->ab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	tour_1(t_stack *stack, int x)
{
	int	i;
	int	y;

	i = stack->atop;
	while (i < stack->size)
	{
		if (stack->ab[i] == x)
			break ;
		i++;
	}
	if (i - stack->atop < (stack->size - stack->atop) / 2)
	{
		y = i - stack->atop;
		while (y-- > 0)
			ra(stack, 1, 1);
	}
	else
	{
		y = stack->size - i;
		while (y-- > 0)
			rra(stack, 1, 1);
	}
}

int	absolu(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	cont(int x, int y)
{
	if (x * y >= 0)
	{
		if (absolu(x) > absolu(y))
			return (absolu(x));
		else
			return (absolu(y));
	}
	if (x * y < 0)
		return (absolu(x - y));
	return (0);
}
