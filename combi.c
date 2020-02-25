/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:09:45 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:09:46 by bminner          ###   ########.fr       */
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
	zero(arg, n, combi);
	moins(arg, n, combi);
	if (nbr(arg, n, combi) == 0)
		star_len(ap, arg, n, combi);
	if (precision(arg, n, combi) == 1)
		if (nbr_pre(arg, n, combi) == 0 && arg[*n] == '*')
			star_pres(ap, arg, n, combi);
	return ;
}

int		printstring(t_flag *combi, char *dest)
{
	int n;

	n = 0;
	while (dest[n] != '\0' || (dest[n] == '\0' && combi->iszero == 1))
	{
		if (dest[n] == '\0')
		{
			combi->iszero--;
			write(1, "\0", 1);
		}
		else
			write(1, &dest[n], 1);
		n++;
	}
	ft_free(&dest, 0);
	return (n);
}
