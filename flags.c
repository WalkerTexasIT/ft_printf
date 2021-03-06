/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:46:47 by bminner           #+#    #+#             */
/*   Updated: 2020/01/13 10:53:18 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		moins(char const *arg, int *n, t_flag *combi)
{
	while (arg[*n] == '-')
	{
		combi->m = 1;
		(*n)++;
	}
	return (0);
}

int		zero(char const *arg, int *n, t_flag *combi)
{
	while (arg[*n] == '0')
	{
		combi->zero = 1;
		(*n)++;
	}
	return (0);
}

int		nbr(char const *arg, int *n, t_flag *combi)
{
	int i;

	i = 0;
	while (arg[*n] >= '0' && arg[*n] <= '9')
	{
		combi->len = combi->len * 10 + arg[*n] - 48;
		(*n)++;
		i = 1;
	}
	return (i);
}

int		star_pres(va_list ap, char const *arg, int *n, t_flag *combi)
{
	int i;

	if (arg[*n] == '*')
	{
		i = va_arg(ap, int);
		if (i >= 0)
			combi->p = i;
		else
			combi->p = -1;
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
		if (combi->len < 0)
		{
			combi->m = 1;
			combi->len *= -1;
		}
		return (1);
	}
	return (0);
}
