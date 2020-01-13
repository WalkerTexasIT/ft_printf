# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bminner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:23:41 by bminner           #+#    #+#              #
#    Updated: 2020/01/13 11:14:11 by bminner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = ft_printf.c	integer.c	combi.c		flags.c		flags2.c \
	  hexa.c		ft_itoa.c	ft_bzero.c	ft_bspace.c		combi2.c

all:
	$(CC) $(SRC)
