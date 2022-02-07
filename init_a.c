/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:26:37 by rliu              #+#    #+#             */
/*   Updated: 2022/02/07 17:33:36 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct stackswap
{
	int *ab;
	int	*inial;
	int *sort;
	int	atop;
	int size;
} t_stack;
/****************************************************************inialstack*/
int *init_list(int argc, char **argv)
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

void	init_sort(t_stack *stack)
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

void	init_ab(t_stack *stack)
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

/************************************************************printstack*/
void print_nba(int *x, int topa, int size)
{
	write(1, "a: ", 3);
	while (topa < size)
	{
		ft_putnbr_fd(x[topa], 1);
		write(1," ", 1);
		topa++;
	}
	write(1, "\n", 1);
}

void print_nbb(int *x, int topa)
{
	write(1, "b: ", 3);
	while (topa>0)
	{
		ft_putnbr_fd(x[topa-1], 1);
		write(1, " ", 1);
		topa--;
	}
	write(1, "\n", 1);
}

void print_stack(int *s, int atop, int size)
{
	print_nba(s, atop, size);
	print_nbb(s, atop);
}

/***************************************************************operations*/

void pb(t_stack *stack, int p)
{
	if (stack->atop < stack->size - 1)
		stack->atop += 1;
	if (p)
		write(1,"pb\n", 3);
}

void pa(t_stack *stack, int p)
{
	if (stack->atop > 0)
		stack->atop -= 1;
	if (p)
		write(1,"pa\n", 3);

}

void sa(t_stack *stack, int p)
{
	int temp;

	if (stack->atop < stack->size-1)
	{	
		temp = stack->ab[stack->atop];
		stack->ab[stack->atop] = stack->ab[ stack->atop + 1];
		stack->ab[stack->atop + 1] = temp;
	}
	if (p)
		write(1,"sa\n", 3);
}

void sb(t_stack *stack, int p)
{
	int temp;

	if (stack->atop > 1)
	{	
		temp = stack->ab[stack->atop - 1];
		stack->ab[stack->atop - 1] = stack->ab[ stack->atop - 2];
		stack->ab[stack->atop - 2] = temp;
	}
	if (p)
		write(1,"sb\n", 3);

}

void ra(t_stack *stack, int p)
{
	int temp;
	int i;
	
	if (stack->atop < stack->size - 1)
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

void rra(t_stack *stack, int p)
{
	int	temp;
	int i;

	if (stack->atop < stack->size - 1)
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

void rb(t_stack *stack, int p)
{
	int temp;
	int i;

	if (stack->atop > 1)
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

void rrb(t_stack *stack, int p)
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

void ss(t_stack *stack)
{
	sa(stack,0);
	sb(stack,0);
	write(1,"ss\n",3);
}

void rr(t_stack *stack)
{
	ra(stack,0);
	rb(stack,0);
	write(1,"rr\n",3);
}

void rrr(t_stack *stack)
{
	rra(stack,0);
	rrb(stack,0);
	write(1,"rrr\n",4);
}


/********************************************************/
void testoperation(t_stack *stack)
{
	pb(stack,1);
	pb(stack,1);
	pb(stack,1);
	pb(stack,1);
	pa(stack,1);
//	pa(stack,1);
	sa(stack,1);
	sb(stack,1);
	ra(stack,1);
	rra(stack,1);
	rb(stack,1);
	rrb(stack,1);
	ss(stack);
	rr(stack);
	rrr(stack);
}
/*******************************************************sort*/


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

int	sort_checkb(t_stack *stack)
{	
	int i;

	i = stack->atop - 1;
	if (i > 0)
	{
		while (i > 0)
		{
			if (stack->ab[i] > stack->ab[i - 1]) 
				return (0);
			i--;
		}
	}
	return (1);
}

int sort_checkbr(t_stack *stack)
{
	int i;

	i = stack->atop -1;
	if (i > 0)
	{
		while (i > 0)
		{
			if (stack->ab[i] < stack->ab[i -1])
				return (0);
			i--;
		}
	}
	return (1);
}

int sort_checkthreea(t_stack *stack)
{
	if (stack->ab[stack->atop] < stack->ab[stack->atop + 1] && stack->ab[stack->atop  + 1] > stack->ab[stack->size - 1])
		return (1);
	else
		return (0);
}

int sort_checktreebr(t_stack *stack)
{
	if (stack->ab[stack->atop] - 1 > 1)
	{
		if (stack->ab[stack->atop] - 1 > stack->ab[stack->atop - 2] && stack->ab[stack->atop -1] < stack->ab[stack->size - 1])
			return (1);
		else 
			return (0);
	}
}

void	sort_1(t_stack *stack)
{
	while(!sort_check(stack))
	{
		if (stack->ab[stack->atop] > stack->ab[stack->size - 1])
		{
			if (stack->ab[stack->atop] > stack->ab[stack->atop + 1])
				ra(stack,1);
			else
				rra(stack,1);
		}
		else
			sa(stack,1);
	}		
}
void	sort_2(t_stack *stack)
{
	while(!sort_check(stack))
	{

		if (stack->ab[stack->atop] > stack->ab[stack->atop + 1] && stack ->ab[stack->atop] != stack->size - 1)
			sa(stack, 1);
		ra(stack, 1);
	}
}
void	sort_3(t_stack *stack)
{
	int i;

	i = stack->size/2;
	j = i;
	while(!sort_check(stack))
	{
		while (!sort_checka(stack))
		{
		
			if (stack->ab[stack->atop] > stack->ab[stack->atop + 1] && stack ->ab[stack->atop] != stack->size - 1)
				sa(stack, 1);
			if (stack->ab[stack->atop] i)
			{
				pb(stack, 1);
				i++;
			}
			else
				ra(stack, 1);
		}
		pa(stack, 1);:wq
	}
}


void	sort_4(t_stack *stack)
{
	int i;

	i = 0;
	while(!sort_check(stack))
	{
		while (!sort_checka(stack))
		{
			sort_1(stack);
			if (stack->ab[stack->atop] == i)
			{
				pb(stack, 1);
				i++;
			}
			else                                                                                                                                                                                                                                                        
				ra(stack, 1);
		}
		pa(stack, 1);
	}
}


/*void	action_1(t_stack *stack)
{
	while
}*/

void	sort_5(t_stack *stack)
{
	while(!sort_check(stack))
	{	
		while (stack->atop < stack->size / 2)
		{
			
		}	
}
/*****************************************************intmain*/

int main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	stack->inial = init_list(argc, argv);
	stack->sort = init_list(argc,argv);
	stack->atop = 0;
	stack->size = argc-1;
	init_sort(stack);
	init_ab(stack);
	sort_1(stack);
	print_stack(stack->inial, stack->atop, argc-1);
	print_stack(stack->sort, stack->atop, argc-1);
	print_stack(stack->ab, stack->atop, argc-1);
	free(stack->ab);
	free(stack->inial);
	free(stack->sort);
	free(stack);
	return (0);
}

