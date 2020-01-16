# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bminner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:23:41 by bminner           #+#    #+#              #
#    Updated: 2020/01/14 14:26:31 by bminner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
	combi.c \
	flags.c \
	flags2.c \
	print_%.c \
	utils.c

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

so: $(OBJ) ft_printf.h
	$(CC) -shared -fPIC -Wl,-soname,ft_printf.so -o ft_printf.so $(OBJ)
