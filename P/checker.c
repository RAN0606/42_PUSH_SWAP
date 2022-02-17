/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:43:29 by rliu              #+#    #+#             */
/*   Updated: 2022/02/17 17:15:05 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void order_init(t_order *orders)
{
	orders[0]->f = &sa;
	orders[0]->name = "sa\n";
	orders[1]->f = &sb;
	orders[1]->name = "sb\n";
	orders[2]->f = &ss;
	orders[2]->name = "ss\n";
	orders[3]->f = &pa;
	orders[3]->name = "pa\n";
	orders[4]->f = &pb;
	orders[4]->name = "pb\n";
	orders[5]->f = &ra;
	orders[5]->name = "ra\n";
	orders[6]->f = &rb;
	orders[6]->name = "rb\n";
	orders[7]->f = &rr;
	orders[7]->name = "rr\n";
	orders[8]->f = &rra;
	orders[8]->name = "rra\n";
	orders[9]->f = &rrb;
	orders[9]->name = "rrb\n";
	orders[10]->f = &rrr;
	orders[10]->name = "rrr\n";	
}

int	act_op(t_stack *stack, t_order *orders, char *line)
{
	int		i;

	i = -1;
	if (line)
	{
		while (++i < 11)
		{
			if (*line == orders[i]->name)
			{
				orders[i]->f(stack, 1, 1);
				return (1);
			}
			if (i == 11)
				return (0);
		}
	}
	return (1);
}

void act_next_op(t_stack *stack)
{
	char	*line;
	
	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
			
	}

}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	
	check_args(argc, argv)
	stack = malloc(sizeof(t_stack));	
}
