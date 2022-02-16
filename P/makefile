# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:01:08 by rliu              #+#    #+#              #
#    Updated: 2022/02/16 17:59:09 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	= 	push_swap

SRCS	=	main.c init_stack.c \
			op_r.c op_rr.c op_sp.c \
			sort_core1.c sort_core2.c sort_utils.c

OBJS 	=	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

IFLAGS	=	-I. -I./libft

LFLAGS	=	-L./libft -lft


%.o:		%.c
			clang $(CFLAGS) $(IFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
			$(MAKE) -C libft
			gcc $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE) -C libft clean
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) -C libft clean
			rm -f $(NAME)

re:			fclean all

.PHONY:     all fclean clean re bonus
