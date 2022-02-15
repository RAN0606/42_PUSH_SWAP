/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:26:37 by rliu              #+#    #+#             */
/*   Updated: 2022/02/14 18:44:22 by rliu             ###   ########.fr       */
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

typedef void (*f)(t_stack *,int,int);

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

/*void	intit_op(void *(*f)(t_stack *, int, int))
{
	


}*/

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


/********************************************************/
/*void testoperation(t_stack *stack)
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
}*/
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

/*int sort_checktreebr(t_stack *stack)
{
	if (stack->ab[stack->atop] - 1 > 1)
	{
		if (stack->ab[stack->atop] - 1 > stack->ab[stack->atop - 2] && stack->ab[stack->atop -1] < stack->ab[stack->size - 1])
			return (1);
		else 
			return (0);
	}
}*/
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
void	sort_1_3b(t_stack *stack)
{
	while (!sort_checkb(stack))
	{
		if (stack->ab[stack->atop-1] > stack ->ab[0])
		{
			if (stack->ab[stack->atop - 1] > stack->ab[stack->atop - 2])
				rb(stack , 1, 1);
			else
				rrb(stack, 1, 1);
		}
		else
			sb(stack,1, 1);
	}
}	
//	print_stack(stack->ab, stack->atop, stack->size);

void	insert_1(t_stack *stack)
{
	int x;
	int y;
	int size;

	size = stack->size;
	x = stack->atop;
	y = size;
	if (stack->ab[stack->atop-1] > stack->ab[x])
	{
		while (stack->ab[stack->atop-1] > stack->ab[x]  && x < size)
		{
			x++;
			if (stack->ab[x] <  stack->ab[x-1] && x < size)
				break;
		}
	}
	else 
	{
		while (stack->ab[stack->atop-1] < stack->ab[y-1] && y > stack->atop)
		{
			y--;
			if (stack->ab[y-1] > stack->ab[y] && y > stack->atop)
				break;
		}
		x = y;
	}
	if (x - stack->atop <= (size-stack->atop)/2)
	{
		y = x-stack->atop;
		while(y-- > 0)
			ra(stack, 1, 1);
		pa(stack, 1, 1);	
	}
	else
	{
		y = size-x;
		while (y-- > 0)
			rra(stack, 1 , 1);
		pa(stack, 1, 1);
	}

}

void	insert_1b(t_stack *stack)
{
	int x;
	int y;
	x= stack->atop-1;
	y= 0;
	if (stack->ab[stack->atop] > stack->ab[x] && x >= 0)
	{
		while (stack->ab[stack->atop] > stack->ab[x] && x >= 0)
		{
			x--;
			if (stack->ab[x] < stack->ab[x+1] && x >=0)
				break;
		}
	}
	else
	{
		while (stack->ab[stack->atop < stack->ab[y]] && y < stack->atop )
		{	
			y++;
			if (stack->ab[y] > stack->ab[y-1] && y < stack->atop ) 
				break;
		}
		x = y;
	}
	if (x > (stack->atop-1)/2)
	{
		y = x - stack->atop -1;
		while(y-- > 0)
			rb(stack, 1, 1);
		pb(stack, 1, 1);	
	}
	else
	{
		y = x;
		while (y-- > 0)
			rrb(stack, 1 , 1);
		pb(stack, 1, 1);
	}
}

void	insert_1br(t_stack *stack)
{
	int x;
	int	y;


	x= stack->atop-1;
	y= 0;
	if (stack->ab[stack->atop] < stack->ab[x] && x >= 0)
	{
		while (stack->ab[stack->atop] < stack->ab[x] && x >= 0)
		{
			x--;
			if (stack->ab[x] > stack->ab[x+1] && x >=0)
				break;
		}
	}
	else
	{
		while (stack->ab[stack->atop > stack->ab[y]] && y < stack->atop )
		{	
			y++;
			if (stack->ab[y] < stack->ab[y-1] && y < stack->atop ) 
				break;
		}
		x = y;
	}
	if (x > (stack->atop-1)/2)
	{
		y = x - stack->atop -1;
		while(y-- > 0)
			rb(stack, 1, 1);
		pb(stack, 1, 1);	
	}
	else
	{
		y = x;
		while (y-- > 0)
			rrb(stack, 1 , 1);
		pb(stack, 1, 1);
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


/*void	tour_1b(t_stack *stack, int x)
{
	int i;
	int y;
	int size;
	
	i = stack->atop;
	size = stack->size;
}
int check_atour(t_stack *stack)
{
	int i;
	
	i = stack->atop;
	while (i < stack->size)
	{
		if ()

	}
}*/



void sort_1_5(t_stack *stack)
{
	int i;
	int x;

	x = stack->size;
	i = 0;
	if (!sort_check(stack))
	{
		while  (stack->ab[stack->atop] > x/2)
		{
			i++;
			pb(stack, 1, 1);
			if (stack->ab[stack->atop-1] < x*3/4 && stack->ab[stack->atop-1]>= x*3/4 && stack->atop > 1)
			{
				if (stack->ab[stack->atop] <= x/2)
					rr(stack, 1, 1);
				else
					rb(stack, 1, 1);
			}
			else
				ra(stack, 1, 1);
			}
		}
		while(stack->atop < stack->size)
		{
			i++;
			pb(stack, 1, 1);
			if (stack->ab[stack->atop-1] < x/4)
					rb(stack, 1, 1);
		}
			pa(stack, 1 , 1);
			pa(stack, 1, 1);
			pa(stack, 1, 1);
			i--;
	

//			print_stack(stack->ab, stack->atop, stack->size);

	
		sort_1_3(stack);
//		print_stack(stack->ab, stack->atop, stack->size);

		while (i-- > 0)
		{
			insert_1(stack);
//			print_stack(stack->ab, stack->atop, stack->size);

		}
		tour_1(stack, 0);	
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
void pre_insert(int x , int y, t_stack * stack)
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
void insert_lazy(t_stack *stack, int range)
{
	int	pos[3];

	pos[0] = 0;
	pos[1] = 0;
	pos[2] = -1 ;

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
		
//		ft_putnbr_fd(x,1);
//		write(1,"x\n",2);
//		ft_putnbr_fd(y,1);
//		write(1,"y\n",2);
//		z = cont(x,y);
//		ft_putnbr_fd(z,1);
//		write(1,"z\n",2);
		if ( stack->ab[i] >= range &&(z < pos[2] || i == stack->atop-1))
		{
			pos[0] = y;
			pos[1] = x;
			pos[2] = z;
//			ft_putnbr_fd(pos[0],1);
//			ft_putnbr_fd(pos[1],1);
//			ft_putnbr_fd(pos[2],1);
		}
		i--;
		x = stack->atop;
		y = stack->size;
		z = 0;
	}
	pre_insert(pos[0], pos[1], stack);
	pa(stack, 1, 1);
}




void sort_1_6 (t_stack *stack)
{
	int i;
	int x;

	x = stack->size;
	i = 0;
	if (!sort_check(stack))
	{
		while  (i < x/2)
		{
			if (stack->ab[stack->atop] >= x / 2)
			{
				pb(stack, 1, 1);
				if (stack->ab[stack->atop-1] < 3*x/4 && stack->atop>1)
				{
					if (stack->atop < x/2)
						rr(stack, 1, 1);
					else
						rb(stack, 1, 1);
				}
				i++;
			}
			else
				ra(stack, 1, 1);
		}
		
		while (stack->atop < stack->size-3)
		{
			pb(stack, 1, 1);
			if (stack->ab[stack->atop-1] < x/2)
				rb(stack, 1, 1);
			i++;
		}	
		sort_1_3(stack);

//		print_stack(stack->ab, stack->atop, stack->size);

		while (i-- > stack->size/2)
		{
			insert_lazy(stack, stack->size/2);
//			print_stack(stack->ab, stack->atop, stack->size);
//
		}

		while (i-- >= 0)
		{
			insert_lazy(stack, 0);
//			print_stack(stack->ab, stack->atop, stack->size);

		}

		tour_1(stack, 0);
	
	}
}


//void	sort_1_more(t_stack *stack)

/*void	sort_2(t_stack *stack)
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
}*/

int	checksize(int *k, int size)
{
	int i;

	i = 0;
	while (i < size)
	{ 
		if (k[i] < 9)
			return (1);
	}
	return (0);
}


void	comt(int *k, int size)
{
	int i;
	i = 0;
	while (i < size && k[i])
	{
		if (k[i] == 12)
		{
			k[i] = 1;
			k[i+1] += 1;
		}
		i++;
	}
}

void	sort_5(t_stack *stack, int size)
{
//	char	*opp[size + 1];
	f		op[11]={&pb,&sa,&ra,&rra,&ss,&rr,&rrr,&pa,&sb,&rb,&rrb};
//	f		opr[11]={&ss,&rrr,&rr,&sa,&sb,&rra,&rrb,&ra,&rb};
	char	*ops[11]={"pb\n", "ss\n", "rr\n", "rrr\n","sa\n" "ra\n", "rra\n", "sb\n", "rb\n", "rrb\n", "pa\n"};
	int	i;
//	int j;
	int k[size];
	i = -1;
	while (++i < size)
		k[i] = -1;
	while (!sort_check(stack))
	{
//		write(1,"test0\n",6);
		init_ab(stack);
		stack->atop = 0;
		k[0] += 1;
		if (k[0] == 11)
		{
//			write(1,"test1\n",6);
			i = 0;
			while (i < size && k[i] > -1)
			{
//				write(1,"test2\n",6);
				if (k[i] == 11 && i < size  - 1)
				{
					k[i] = 0;
					k[i + 1] += 1;
				}
				else if (k[i] == 11 && i == size - 1)
					return;
				i++;
			}
		}
		i = 0;
		while (i < size && k[i] > -1)
		{	
//			write(1,"operation\n", 2);
			op[k[i]](stack, 1, 0);
//			print_stack(stack->ab, stack->atop, 5);
			i++;
		}
	}
	i = 0;
	if (sort_check(stack))
	{
		while (i < size && k[i] > -1)
		{
			op[k[i]](stack, 0 , 1);
			i++;
		}
	}
}

/*int	check_i(int x, int y)
{
	return (y - x);
}
void sort_6(t_stack stack)
{
	int i;
	i = 0;
	while (!sort_check(stack))
	{
		
	}
		
}*/
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
/*	pb(stack,1,1);
	ss(stack,1,1);
	sa(stack,1,1);
	ra(stack,1,1);
		
	ra(stack,1,1);
	ra(stack,1,1);
	sa(stack,1,1);
*/

	sort_1_6(stack);
//	print_stack(stack->inial, stack->atop, argc-1);
//	print_stack(stack->sort, stack->atop, argc-1);
//	print_stack(stack->ab, stack->atop, argc-1);
	free(stack->ab);
	free(stack->inial);
	free(stack->sort);
	free(stack);
	return (0);
}

