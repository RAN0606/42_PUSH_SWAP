# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:01:08 by rliu              #+#    #+#              #
#    Updated: 2022/02/18 17:02:57 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	= 	push_swap

CHECKER	=	checker

SRCS	=	main.c paras.c init_stack.c \
			op_r.c op_rr.c op_sp.c \
			sort_core1.c sort_core2.c sort_utils.c


SRCS_C	=	checker.c paras.c init_stack.c \
			op_r.c op_rr.c op_sp.c \
			sort_core1.c sort_core2.c sort_utils.c

OBJS 	=	$(SRCS:.c=.o)

OBJS_C	=	$(SRCS_C:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

IFLAGS	=	-I. -I./libft

LFLAGS	=	-L./libft -lft


%.o:		%.c
			clang $(CFLAGS) $(IFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
			$(MAKE) -C libft
			gcc $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(NAME)

$(CHECKER):	$(OBJS_C)
			$(MAKE) -C libft
			gcc $(CFLAGS) $(OBJS_C) $(LFLAGS) $(IFLAGS) -o $(CHECKER)

all:		$(NAME) $(CHECKER)

clean:
			$(MAKE) -C libft clean
			rm -f $(OBJS)
			rm -f $(OBJS_C)

fclean:		clean
			$(MAKE) -C libft fclean
			rm -f $(NAME)
			rm -f $(CHECKER)

re:			fclean all

.PHONY:     all fclean clean re bonus
