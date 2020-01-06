/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:20:17 by bminner           #+#    #+#             */
/*   Updated: 2020/01/06 14:46:07 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		verif(char const *arg, int *n)
{
	char	*list;
	int		i;

	list = "cspdiuxX%";
	i = 0;
	while (list[i] != '\0')
	{
		if (arg[*n] == list[i])
			return (1);
		i++;
	}
	return (0);
}

void	check(va_list ap, char const *arg, int *n, t_flag *combi)
{
	moins(arg, n, combi);
	if (nbr(arg, n, combi) == 0)
		star_len(ap, arg, n, combi);
	if (verif(arg, n) == 1)
		return ;
	if (precision(arg, n, combi) == 1)
		if (nbr_pre(arg, n, combi) == 0)
			star_pres(ap, arg, n, combi);
	return ;
}

int		combi(va_list ap, char const *arg, int *n)
{
	t_flag	combi;

	combi.zero = 0;
	combi.moins = 0;
	combi.precision = 0;
	combi.len = 0;
	return (find_format(ap, arg, n, &combi));
}
