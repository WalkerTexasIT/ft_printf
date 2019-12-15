/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2019/12/15 16:09:53 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
/*
typedef struct t_flag s_flag;
struct s_flag {
	int		zero;
	int		moins;
	int		point;
	int		star;
	int 	nbr;
};*/

int			ft_printf(const char *arg, ...);
int			ft_putnbr (int n);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr_unsigned(unsigned int nb);
int			convert_hexa(unsigned int nb);
int			convert_hexa_maj(unsigned int nb);
int			print_porcent(void);
int			aff_pointeur(unsigned long long n, int i);
int			ft_puthexa(int n);

/*void		moins(char const *arg, int *n, flag *combi);
void		zero(char const *arg, int *n, flag *combi);
void		point(char const *arg, int *n, flag *combi);
void		star(char const *arg, int *n, flag *combi);*/

#endif
