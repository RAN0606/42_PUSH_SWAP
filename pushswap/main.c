/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:31:24 by rliu              #+#    #+#             */
/*   Updated: 2022/02/21 16:46:37 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = 0;
	if (check_args(argc, argv))
	{
		stack = ft_calloc(1, sizeof(t_stack));
		if (!stack)
			return (0);
		init_stack(stack, argc, argv);
		if (argc < 5)
			sort_1_3(stack);
		else
			sort_1_6(stack);
		stack_free(stack);
	}
	return (0);
}
