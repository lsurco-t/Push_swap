# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 09:53:34 by lsurco-t          #+#    #+#              #
#    Updated: 2025/06/10 13:17:35 by lsurco-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = libft_dir/libft.a
SRC = push_swap.c
OBJ = $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(cc) $(CFLAGS) -o $@ $^

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f -C $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f -C $(OBJ) $(LIBFT) 

re: fclean all

.PHONY: all clean fclean re
