/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:46:47 by bminner           #+#    #+#             */
/*   Updated: 2020/01/06 09:16:01 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		moins(char const *arg, int *n, t_flag *combi)
{
	if (arg[*n] == '-')
	{
		combi->moins = 1;
		(*n)++;
		return (1);
	}
	return (0);
}

int		zero(char const *arg, int *n, t_flag *combi)
{
	if (arg[*n] == '0')
	{
		combi->zero = 0;
		(*n)++;
		return (1);
	}
	return (0);
}

int		nbr(char const *arg, int *n, t_flag *combi)
{
	int i;

	i = 0;
	while (arg[*n] >= '1' || arg[*n] <= '9')
	{
		combi->len *= 10;
		combi->len += (int)arg[*n];
		(*n)++;
		i = 1;
	}
	return (i);
}

int		star_pres(va_list ap, char const *arg, int *n, t_flag *combi)
{
	if (arg[*n] == '*')
	{
		combi->precision = va_arg(ap, int);
		(*n)++;
		return (1);
	}
	return (0);
}

int		star_len(va_list ap, char const *arg, int *n, t_flag *combi)
{
	if (arg[*n] == '*')
	{
		combi->len = va_arg(ap, int);
		(*n)++;
		return (1);
	}
	return (0);
}

int		nbr_pre(char const *arg, int *n, t_flag *combi)
{
	int i;

	i = 0;
	while (arg[*n] >= '1' && arg[*n] <= '9')
	{
		combi->precision *= 10;
		combi->precision += (int)arg[*n];
		(*n)++;
		i = 1;
	}
	return (i);
}
