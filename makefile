# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:01:08 by rliu              #+#    #+#              #
#    Updated: 2022/02/21 16:42:15 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	= 	push_swap

BONUS	=	bonus

SRCS	=	pushswap/main.c pushswap/paras.c pushswap/init_stack.c \
			pushswap/op_r.c pushswap/op_rr.c pushswap/op_sp.c \
			pushswap/sort_core1.c pushswap/sort_core2.c pushswap/sort_utils.c


SRCS_C	=	pushswap_bonus/checker.c pushswap/paras.c pushswap/init_stack.c \
			pushswap/op_r.c pushswap/op_rr.c pushswap/op_sp.c \
			pushswap/sort_core1.c pushswap/sort_core2.c pushswap/sort_utils.c \
			pushswap_bonus/get_next_line.c

OBJS 	=	$(SRCS:.c=.o)

OBJS_C	=	$(SRCS_C:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror -fPIE

IFLAGS	=	-I. -I./libft

LFLAGS	=	-L./libft -lft


%.o:		%.c
			clang $(CFLAGS) $(IFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
			$(MAKE) -C libft
			gcc $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(NAME)

$(BONUS):		$(OBJS_C)
			$(MAKE) -C libft
			gcc $(CFLAGS) $(OBJS_C) $(LFLAGS) $(IFLAGS) -o checker

all:		$(NAME) $(BONUS)

clean:
			$(MAKE) -C libft clean
			rm -f $(OBJS)
			rm -f $(OBJS_C)

fclean:		clean
			$(MAKE) -C libft fclean
			rm -f $(NAME)
			rm -f checker

re:			fclean all

.PHONY:     all fclean clean re bonus
