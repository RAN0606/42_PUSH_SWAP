/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:26:55 by rliu              #+#    #+#             */
/*   Updated: 2022/02/21 11:33:21 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 1
# include "push_swap.h"

typedef void	(*t_f)(t_stack *,int,int);
char	*get_next_line(int fd);

#endif
