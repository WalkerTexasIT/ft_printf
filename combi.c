/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:20:17 by bminner           #+#    #+#             */
/*   Updated: 2019/12/19 12:07:24 by bminner          ###   ########.fr       */
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

void	check(va_list ap, char const *arg, int *n)
{
	if (	
}

int		combi(va_list ap, char const *arg, int *n)
{
	t_flag	combi;

	combi.zero = 0;
	combi.moins = 0;
	combi.point = 0;
	combi.star = 0;
	combi.nbr = 1;
	return (find_format(ap, arg, n, &combi));
}
