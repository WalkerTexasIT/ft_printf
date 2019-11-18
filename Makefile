# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bminner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:23:41 by bminner           #+#    #+#              #
#    Updated: 2019/11/14 13:32:13 by bminner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
		ar rc $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CCFLAGS) -c -o $@ $<
	
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

so: $(OBJ) libft.h
	$(CC) -shared -fPIC -Wl,-soname,libftprintf.so -o libftprintf.so $(OBJ)
