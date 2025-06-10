# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 09:53:34 by lsurco-t          #+#    #+#              #
#    Updated: 2025/06/10 10:39:59 by lsurco-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = push_swap
cc = cc
CFLAGS = -Wall -Wextra -Werror
libft = /libft/libft.a
src = push_swap.c
obj = $(src:.c=.o)

all: $(name)

$(name): $(obj)
	$(cc) $(CFLAGS) -o $@ $^

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re: fclean all

.PHONY: all clean fclean re
