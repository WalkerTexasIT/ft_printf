/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:08:27 by bminner           #+#    #+#             */
/*   Updated: 2020/01/06 11:57:12 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision(char const *arg, int *n, t_flag *combi)
{
	if (arg[*n] == '.')
	{
		combi->precision = -2;
		(*n)++;
		return (1);
	}
	return (0);
}

int		nbr_pre(char const *arg, int *n, t_flag *combi)
{
	int i;

	i = 0;
	combi->precision = 0;
	while (arg[*n] >= '0' && arg[*n] <= '9')
	{
		combi->precision = combi->precision * 10 + arg[*n] - 48;
		(*n)++;
		i = 1;
	}
	return (i);
}
