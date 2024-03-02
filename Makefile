# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 02:55:39 by aes-sayo          #+#    #+#              #
#    Updated: 2024/02/25 21:30:16 by aes-sayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address

SRCS= srcs/push_swap.c srcs/algorithms_utils.c srcs/functions_utils.c srcs/other_functions.c srcs/stack_functions.c srcs/subject_functions_2.c srcs/subject_functions.c srcs/subject_functions_gen.c srcs/new_algo.c
OBJS=$(SRCS:.c=.o)
SRCSB= bonus/subject_functions.c bonus/subject_functions_2.c bonus/subject_functions_gen.c bonus/stack_functions.c bonus/other_functions.c bonus/functions_utils.c bonus/checker.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c 
OBJSB=$(SRCSB:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a

bonus :	$(OBJSB)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o checker $(OBJSB) ./libft/libft.a
	
clean :
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
