/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:13 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:15 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printlen(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (combi->zero == 1 && combi->moins == 0)
		dest = ft_malloc_zero(combi->len);
	else
		dest = ft_malloc_space(combi->len);
	if (combi->moins == 1)
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	else
	{
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*printminlen(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	dest = ft_malloc_space(combi->len);
	if (combi->moins == 1)
		while (i < ft_strlen(toprint))
		{
			dest[i] = toprint[i];
			i++;
		}
	else
	{
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*print_string(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (toprint == 0)
		toprint = "(null)";
	else
		if ((toprint = ft_strdup((const char*)toprint)) == 0)
			return (0);
	if (combi->precision != -1 && combi->precision >= combi->len && combi->precision <= ft_strlen(toprint))
	{
		dest = ft_malloc_space(combi->precision);
		while (i < combi->precision)
		{
			dest[i] = toprint[i];
			i++;
		}
	}
	else if (combi->len > combi->precision && combi->precision >= ft_strlen(toprint))
	{
		dest = ft_malloc_space(combi->len);
		if (combi->moins == 1)
			n = 0;
		else
			n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->precision > ft_strlen(toprint) && combi->len < ft_strlen(toprint))
		dest = toprint;
	else if (combi->precision > combi->len && combi->len > ft_strlen(toprint))
		dest = printminlen(combi, toprint);
	else if (combi->len > combi->precision && combi->precision != -1)
	{
		if (combi->zero == 0)
			dest = ft_malloc_space(combi->len);
		else
			dest = ft_malloc_zero(combi->len);
		if (combi->moins == 1)
			while (toprint[i] != '\0' && i < combi->precision)
				dest[n++] = toprint[i++];
		else
		{
			n = combi->len - combi->precision;
			while (toprint[i] != '\0' && n < combi->len)
				dest[n++] = toprint[i++];
		}
	}
	else if (combi->len > ft_strlen(toprint))
		dest = printlen(combi, toprint);
	else
		dest = toprint;
	return (dest);
}