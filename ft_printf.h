/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2019/12/17 15:23:57 by bminner          ###   ########.fr       */
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
	int 	lenarg;
	int		lentoprint;

};*/

int			ft_printf(const char *arg, ...);
char		*ft_putchar(char c);
char		*ft_itoa(int n);
char		*ft_itoa_unsigned(unsigned int n);
char		*print_porcent(void);
char		*aff_pointeur(unsigned long long i);
char		*ft_hexatoa(unsigned int n);
char		*ft_hexatoa_maj(unsigned int n);
int			ft_puthexa(int n);
int			ft_lenhexa(long long n);

/*void		moins(char const *arg, int *n, flag *combi);
void		zero(char const *arg, int *n, flag *combi);
void		point(char const *arg, int *n, flag *combi);
void		star(char const *arg, int *n, flag *combi);*/

#endif
