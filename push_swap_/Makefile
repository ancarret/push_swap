# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 16:21:08 by ancarret          #+#    #+#              #
#    Updated: 2025/06/23 11:13:53 by ancarret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = operations.c operations_utils.c turk_algorithm.c more_operations.c \
		algorithm_utils.c algorithm_utils_2.c main.c check_arguments.c \
		ft_atolong.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re