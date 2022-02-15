/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:16:32 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 19:27:21 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_check(t_stack *stack)
{
	int i;
	
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
	int i;

	i = stack->atop;
	while (i < stack->size - 1)
	{
		if (stack->ab[i] > stack->ab[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}


/**********************************************************************/
void	sort_1_3(t_stack *stack)
{
	while(!sort_checka(stack))
	{
		if (stack->ab[stack->atop] > stack->ab[stack->size - 1])
		{
			if (stack->ab[stack->atop] > stack->ab[stack->atop + 1])
				ra(stack,1,1);
			else
				rra(stack,1,1);
		}
		else
			sa(stack,1,1);
	}
}

void	tour_1(t_stack *stack, int x)
{
	int i;
	int y;
	int size;
	
	i = stack->atop;
	size =stack->size;
	while (i < size)
	{
		if (stack->ab[i] == x)
			break;
		i++;
	}
	if (i - stack->atop < (size-stack->atop)/2)
	{
		y = i-stack->atop;
		while(y-- > 0)
			ra(stack, 1, 1);
	}
	else
	{
		y = size-i;
		while (y-- > 0)
			rra(stack, 1 , 1);
	}
}


int absolu(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
int	cont(int x, int y)
{
	if (x*y >= 0)
	{
		if (absolu(x) > absolu(y))
			return (absolu(x));
		else 
			return (absolu(y));
	}
	if (x*y < 0)
		return (absolu(x-y));
	return (0);
}

static void pre_insertsigle(int x, int y, t_stack *stack)
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
void pre_insertdouble(int x , int y, t_stack *stack)
{
	while (x > 0 && y > 0)
	{
		rr(stack , 1 ,1);
		x--;
		y--;
	}
	while (x < 0 && y < 0)
	{
		rrr(stack, 1, 1);
		x++;
		y++;
	}
	pre_insertsigle(x, y,stack);
}
void insert(t_stack *stack, int range)
{
	int	pos[3];

	pos[2] =-1;

	int x;
	int y;
	int z;
	int i;

	i = stack->atop-1;
	x = stack->atop;
	y = stack->size;
	z = 0;


	while (i >= 0 )
	{
		if (stack->ab[i] > stack->ab[x])
		{
			while (stack->ab[i] > stack->ab[x]  && x < stack->size)
			{
				x++;
				if (stack->ab[x] <  stack->ab[x-1] && x < stack->size)
					break;
			}
		}
		else 
		{
			while (stack->ab[i] < stack->ab[y-1] && y > stack->atop)
			{
				y--;
				if (stack->ab[y-1] > stack->ab[y] && y > stack->atop)
					break;
			}
			x = y;
		}
		if (x - stack->atop <=(stack->size-stack->atop)/2)
			y = x-stack->atop;
		else
			y = x - stack->size;
		if (i >= stack->atop / 2)
			x = stack->atop - 1 - i;
		else
			x = -(i + 1);
		z = cont(y,x);
		if ( stack->ab[i] >= range &&((z < pos[2] && z>=0) || i == stack->atop-1))
		{
			pos[0] = y;
			pos[1] = x;
			pos[2] = z;
		}
		if (pos[2] == 0 || pos[2] ==1)
			break;
		i--;
		x = stack->atop;
		y = stack->size;
		z = -1;
	}
	pre_insertdouble(pos[0], pos[1], stack);
	pa(stack, 1, 1);
}

static void sort_insert(t_stack *stack)
{
	int i;

	i = 0;
	while  (i < stack->size / 2)
	{
		if (stack->ab[stack->atop] < stack->size / 2)
		{
			pb(stack, 1, 1);
			i++;
		}
		else
			ra(stack, 1, 1);
	}	
	while (stack->atop < stack->size - 3)
	{
		pb(stack, 1, 1);
		i++;
	}	
	sort_1_3(stack);
	while (i-- >= 0)
		insert(stack, 0);
}

void sort_1_6 (t_stack *stack)
{
	if (!sort_check(stack))
	{
		sort_insert(stack);
		tour_1(stack, 0);
	}
}
		

