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
	print_porcent.c \
	print_bigx.c \
	print_c.c \
	print_d.c \
	print_p.c \
	print_s.c \
	print_u.c \
	print_x.c \
	utils.c \
	utils2.c \
	print_d1.c \
	print_d2.c \
	print_s1.c \
	print_u1.c \
	print_x1.c

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

