# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memillet <memillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 01:27:26 by memillet          #+#    #+#              #
#    Updated: 2025/11/17 03:20:22 by memillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = pipex.c utils.c

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	@make re -C ./libft
	$(CC) $(CFLAGS) $(OBJECTS) libft/libft.a -o $(NAME)

%.o: %.c push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@make clean -C ./libft
	$(RM) $(OBJECTS)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re