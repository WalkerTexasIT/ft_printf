# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bminner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:23:41 by bminner           #+#    #+#              #
#    Updated: 2019/12/15 12:23:10 by bminner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = ft_printf.c	integer.c	string.c

all:
	$(CC) $(SRC)
