# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bminner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:23:41 by bminner           #+#    #+#              #
#    Updated: 2020/01/06 12:08:07 by bminner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = ft_printf.c	integer.c	combi.c		flags.c		flags2.c \
	  hexa.c		ft_itoa.c

all:
	$(CC) $(SRC)
