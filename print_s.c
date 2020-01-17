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

char	*printminpre(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;
	int		n;

	dest = ft_malloc_space(combi->len);
	i = 0;
	if (combi->moins == 1)
		while (i < combi->precision)
		{
			dest[i] = toprint[i];
			i++;
		}
	else
	{
		n = combi->len - combi->precision;
		while (i < combi->precision && toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*print_string(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;

	i = 0;
	if (combi->precision != 0 && combi->precision >= combi->len && combi->precision <= ft_strlen(toprint))
	{
		dest = ft_malloc_space(combi->precision);
		while (i < combi->precision)
		{
			dest[i] = toprint[i];
			i++;
		}
	}
	else if (combi->precision != 0 && combi->len > combi->precision)
		dest = printminpre(combi, toprint);
	else if (combi->precision > ft_strlen(toprint) && combi->len < ft_strlen(toprint))
		dest = toprint;
	else if (combi->precision > combi->len && combi->len > ft_strlen(toprint))
		dest = printminlen(combi, toprint);
	else
		dest = toprint;
	return (dest);
}