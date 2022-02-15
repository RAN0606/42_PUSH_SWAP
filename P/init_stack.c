/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:22 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 18:36:17 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *init_list(int argc, char **argv)
{
	int i;
	int *x;
	
	x = malloc((argc-1)*sizeof(int));
	if (!x)
		return (0);
	i = 1;
	while (i < argc)
	{
		x[i-1] = ft_atoi(argv[i]);
		i++;	
	}
	return(x);
}

static void	init_sort(t_stack *stack)
{
	int i;
	int temp;
	int size;
	
	size = stack->size - 1;
	while (size > 0)
	{
		i = 0;
		while (i < size)
	    {
			if (stack->sort[i] > stack->sort[i + 1])
			{
				temp = stack->sort[i];
				stack->sort[i] = stack->sort[i + 1];
				stack->sort[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}

static void	init_ab(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	stack->ab = malloc(stack->size * sizeof(int));
	while (i < stack->size)
	{
		j = 0;
		while(j < stack->size)
		{
			if (stack->inial[i] == stack->sort[j])
			{
				stack->ab[i] = j;
				break;
			}
			j++;
		}
		i++;

	}
}

void init_stack(t_stack *stack, int argc, char **argv)
{
	stack->inial = init_list(argc, argv);
	stack->sort = init_list(argc,argv);
	stack->atop = 0;
	stack->size = argc-1;
	init_sort(stack);
	init_ab(stack);
}
