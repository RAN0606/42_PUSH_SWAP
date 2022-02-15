/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:31:24 by rliu              #+#    #+#             */
/*   Updated: 2022/02/15 18:40:59 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	init_stack(stack, argc, argv);
	sort_1_6(stack);
	free(stack->ab);
	free(stack->inial);
	free(stack->sort);
	free(stack);
	return (0);
}

