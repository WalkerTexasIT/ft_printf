/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2020/01/13 11:34:18 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_flag {
	int			zero;
	int			m;
	int			p;
	int			len;
	int			iszero;
}				t_flag;

int				ft_printf(const char *arg, ...);
int				verif(char const *arg, int *n);
int				combi(va_list ap, char const *arg, int *n);
int				find_format(va_list ap, char const *arg, int *n, t_flag *combi);
void			check(va_list ap, char const *arg, int *n, t_flag *combi);
int				moins(char const *arg, int *n, t_flag *combi);
int				zero(char const *arg, int *n, t_flag *combi);
int				nbr(char const *arg, int *n, t_flag *combi);
int				star_pres(va_list ap, char const *arg, int *n, t_flag *combi);
int				star_len(va_list ap, char const *arg, int *n, t_flag *combi);
int				nbr_pre(char const *arg, int *n, t_flag *combi);
int				precision(char const *arg, int *n, t_flag *combi);
char			*ft_malloc_zero(int n);
char			*ft_malloc_space(int n);
char			*print_porcent(t_flag *combi);
char			*print_char(t_flag *combi, char toprint);
int				ft_strlen(char *src);
char			*print_string(t_flag *combi, char *toprint);
char			*print_integer(t_flag *combi, int num);
char			*print_unsigned(t_flag *combi, unsigned num);
int				ft_lenhexa(long long n);
char			*option3(t_flag *combi, char *toprint, int ca);
int				ft_puthexa_maj(int n);
char			*ft_hexatoa(unsigned int n, int k);
char			*print_hexa(t_flag *combi, unsigned int num, int maj);
int				ft_puthexa(int n);
char			*print_pointer(t_flag *combi, unsigned long long i);
char			*ft_strdup(const char *s1);
char			*ft_free(char **tofree, int ret);
int				ft_free_retint(char **tofree, int ret);
int				printstring(t_flag *combi, char *dest);
char			*dutils6(t_flag *combi, char *toprint, int i, int n);
char			*dutils5(t_flag *combi, char *toprint, int i, int n);
char			*dutils4(t_flag *combi, char *toprint, int i, int n);
char			*dutils3(t_flag *combi, char *toprint, int i, char *dest);
char			*dutils2(t_flag *combi, char *toprint, int i, int n);
char			*dutils1(t_flag *combi, char *toprint, int i, int n);
char			*xutils2(t_flag *combi, char *toprint, int i, int n);
char			*xutils3(t_flag *combi, char *toprint, int i, int n);
char			*cases2(t_flag *combi, char *toprint, int cas);
char			*uutils1(t_flag *combi, char *toprint, int i, int n);
char			*prints4(t_flag *combi, char *toprint, int i, int n);
char			*printlen(t_flag *combi, char *toprint, int n);
char			*putils1(t_flag *combi, char *toprint, int j, int n);

#endif
