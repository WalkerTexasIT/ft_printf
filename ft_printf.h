/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2019/12/18 18:11:31 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_flag s_flag;
struct s_flag {
	int		zero;
	int		moins;
	int		precision;
	int 	len;
};

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

int			moins(char const *arg, int *n, flag *combi);
int			zero(char const *arg, int *n, flag *combi);
int			nbr(char const *arg, int *n, flag *combi);
int			star_pres(va_list ap, char const *arg, int *n, flag *combi);
int			star_len(va_list ap, char const *arg, int *n, flag *combi);
int			nbr_pre(char const *arg, int *n, flag *combi);

#endif
