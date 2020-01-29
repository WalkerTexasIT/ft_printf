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
		dest = ft_malloc_zero(combi->len);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	if (ca == 2)
	{
		dest = ft_malloc_zero(combi->precision);
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

char	*print_hexa_maj(t_flag *combi, unsigned int num)
{
	char	*dest;
	char	*toprint;
	int		i;
	int		n;

	i = 0;
	toprint = ft_hexatoa(num, 2);
	if (combi->len > combi->precision && combi->precision > ft_strlen(toprint))
	{
		dest = ft_malloc_space(combi->len);
		if (combi->moins == 1)
		{
			n = 0;
			while (n < (combi->precision - ft_strlen(toprint)))
				dest[n++] = '0';
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
		}
		else
		{
			n = combi->len - combi->precision;
			while (n < (combi->len - ft_strlen(toprint)))
				dest[n++] = '0';
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
		}
	}
	else if (combi->len > ft_strlen(toprint) && combi->moins == 1 && combi->precision == -1)
		dest = option3(combi, toprint, 1);
	else if (combi->len > ft_strlen(toprint) && combi->precision <= ft_strlen(toprint))
	{
		n = combi->len - ft_strlen(toprint);
		if (combi->zero == 1 && combi->precision == -1 && combi->moins == 0)
			dest = ft_malloc_zero(combi->len);
		else
			dest = ft_malloc_space(combi->len);
		if (combi->moins == 1)
			while (toprint[i] != '\0')
			{
				dest[i] = toprint[i];
				i++;
			}
		else
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
	}
	else if (combi->precision > ft_strlen(toprint))
		dest = option3(combi, toprint, 2);
	else
		return (toprint);
	return (dest);
}
