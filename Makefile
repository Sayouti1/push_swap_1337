# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 02:55:39 by aes-sayo          #+#    #+#              #
#    Updated: 2024/01/26 23:10:36 by aes-sayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS= srcs/push_swap.c srcs/algorithms_utils.c srcs/functions_utils.c srcs/other_functions.c srcs/stack_functions.c srcs/subject_functions_2.c srcs/subject_functions.c srcs/subject_functions_gen.c srcs/new_algo.c
OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a

clean :
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
