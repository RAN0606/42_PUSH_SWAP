/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:31:24 by rliu              #+#    #+#             */
/*   Updated: 2022/02/16 17:04:56 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argerror(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}	
	return (1);
}

int	check_args(int argc, char **argv)
{	
	int	i;

	i = 1;
	if (argc == 1)
		exit (0);
	while (i < argc)
	{
		if (!argerror(argv[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (i > 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	check_args(argc, argv);
	stack = malloc(sizeof(t_stack));
	init_stack(stack, argc, argv);
	if (argc < 5)
		sort_1_3(stack);
	else
		sort_1_6(stack);
	free(stack->ab);
	free(stack->inial);
	free(stack->sort);
	free(stack);
	return (0);
}
