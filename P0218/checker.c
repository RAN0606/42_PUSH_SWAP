/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:43:29 by rliu              #+#    #+#             */
/*   Updated: 2022/02/18 18:11:24 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	order_init(t_f *orders, char **ordername)
{
	orders[0] = &sa;
	ordername[0] = "sa\n";
	orders[1] = &sb;
	ordername[1] = "sb\n";
	orders[2] = &ss;
	ordername[2] = "ss\n";
	orders[3] = &pa;
	ordername[3] = "pa\n";
	orders[4] = &pb;
	ordername[4] = "pb\n";
	orders[5] = &ra;
	ordername[5] = "ra\n";
	orders[6] = &rb;
	ordername[6] = "rb\n";
	orders[7] = &rr;
	ordername[7] = "rr\n";
	orders[8] = &rra;
	ordername[8] = "rra\n";
	orders[9] = &rrb;
	ordername[9] = "rrb\n";
	orders[10] = &rrr;
	ordername[10] = "rrr\n";
}

int	act_one(t_stack *stack, t_f *orders, char *line, char **ordername)
{
	int	i;

	i = -1;
	if (line)
	{
		while (++i < 11)
		{
			if (!ft_strncmp(line, ordername[i], ft_strlen(ordername[i])))
			{
				orders[i](stack, 1, 0);
				return (1);
			}
			if (i == 10)
				return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	int		i;
	int		ret;
	char	line[100];

	ft_bzero(line, 10);
	i = 0;
	ret = read(fd, line, 1);
	while (ret > 0 && line[i] != '\n')
	{
		i++;
		ret = read(fd, line + i, 1);
	}
	if (line[i] == '\n')
		return (ft_strdup(line));
	return (0);
}

void	act_next(t_stack *stack)
{
	t_f		orders[11];
	char	*line;
	char	*ordername[11];

	order_init(orders, ordername);
	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
		if (!act_one(stack, orders, line, ordername))
		{
			write(1, "Error\n", 6);
			free(line);
			stack_free(stack);
			exit (0);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	check_args(argc, argv);
	stack = malloc(sizeof(t_stack));
	init_stack(stack, argc, argv);
	act_next(stack);
	if (sort_check(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(stack);
	return (0);
}
