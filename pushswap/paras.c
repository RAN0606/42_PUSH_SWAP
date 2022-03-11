/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paras.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:50:19 by rliu              #+#    #+#             */
/*   Updated: 2022/02/18 17:50:06 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoill(const char *str)
{
	int				i;
	int				minus;
	long long int	nb;

	i = 0;
	minus = 1;
	nb = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return ((long long int)(nb * minus));
}

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
	return (i);
}

int	check_nb(char **argv, int i)
{
	int	j;

	j = 1;
	if (ft_atoill(argv[i]) > 2147483647 || ft_atoill(argv[i]) < -2147483648)
		return (0);
	while (j < i)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (0);
		j++;
	}
	if (j == i)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{	
	int	i;

	i = 1;
	if (argc == 1)
		exit (0);
	while (i < argc)
	{
		if (!argerror(argv[i]) || !check_nb(argv, i))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	if (i > 1)
		return (1);
	return (0);
}
