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

typedef struct s_flag {
	int		zero;
	int		moins;
	int		precision;
	int 	len;
}			t_flag;

int			ft_printf(const char *arg, ...);
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
char		*ft_malloc_zero(int n);
char		*ft_malloc_space(int n);
char		*print_porcent(t_flag *combi);
int			verif(char const *arg, int *n);
char		*print_char(t_flag *combi, char toprint);

#endif
