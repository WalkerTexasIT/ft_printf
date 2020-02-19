/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:24:34 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:24:36 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*option3(t_flag *combi, char *toprint, int ca)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	if (ca == 1)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	if (ca == 2)
	{
		if ((dest = ft_malloc_zero(combi->precision)) == 0)
			return (0);
		n = combi->precision - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

int		ft_puthexa_maj(int n)
{
	if (0 <= n && n <= 9)
		return (n += 48);
	if (n == 10)
		return ('A');
	if (n == 11)
		return ('B');
	if (n == 12)
		return ('C');
	if (n == 13)
		return ('D');
	if (n == 14)
		return ('E');
	if (n == 15)
		return ('F');
	return (0);
}
