/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:43 by rliu              #+#    #+#             */
/*   Updated: 2022/01/31 12:09:51 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_paraerror(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ( str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}	
	return (1);
}

int ft_paraerror_nbs(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_paraerror(argv[i]))
		{
			write(1, "Error, please verify your nb list", 33);
			return (0);
		}
		i++;
	}
	return (1);
}

t_list	*init_alist(int argc, char **argv)
{	
	t_list	*listargs;
	t_list	*new;
	int	i;
	int nb[argc];

	i = 1;

	while (i < argc)
	{
		if (!ft_paraerror(argv[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		nb[i] = ft_atoi(argv[i]);
		ft_lstadd_back(&listargs, ft_lstnew(&nb[i]));
		i++;	
	}
	return (listargs);
}


int	main(int argc, char **argv)
{
	(void) argc;
	t_list	*x;
	t_list	*temp;
	
	x = init_alist(argc,argv);
	while (x)	
	{
		printf("%d ", *((int *)(x->content)));
		x = x->next;
	}
	return (0);
}

