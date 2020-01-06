/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2020/01/06 12:13:04 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flag {
	int		zero;
	int		moins;
	int		precision;
	int 	len;
}			t_flag;

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
int			combi(va_list ap, char const *arg, int *n);
int			find_format(va_list ap, char const *arg, int *n, t_flag *combi);
void		check (va_list ap, char const *arg, int *n, t_flag *combi);
int			moins(char const *arg, int *n, t_flag *combi);
int			zero(char const *arg, int *n, t_flag *combi);
int			nbr(char const *arg, int *n, t_flag *combi);
int			star_pres(va_list ap, char const *arg, int *n, t_flag *combi);
int			star_len(va_list ap, char const *arg, int *n, t_flag *combi);
int			nbr_pre(char const *arg, int *n, t_flag *combi);
int			precision(char const *arg, int *n, t_flag *combi);

#endif
