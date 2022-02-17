/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:31:24 by rliu              #+#    #+#             */
/*   Updated: 2022/02/17 15:51:12 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_free(t_stack *stack)
{
	free(stack->ab);
	free(stack->inial);
	free(stack->sort);
	free(stack);
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
	stack_free(stack);
	return (0);
}
