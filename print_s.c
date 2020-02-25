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

char	*printlen(t_flag *combi, char *toprint, int n)
{
	char	*dest;
	int		i;

	i = 0;
	if (combi->zero == 1 && combi->m == 0)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
	}
	else
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
	}
	if (combi->m == 1)
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
	if ((dest = ft_malloc_space(combi->len)) == 0)
		return (0);
	if (combi->m == 1)
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

char	*prints3(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->len > ft_strlen(toprint))
	{
		if ((dest = printlen(combi, toprint, 0)) == 0)
			return (ft_free(&toprint, 0));
	}
	else
		return (toprint);
	ft_free(&toprint, 0);
	return (dest);
}

char	*prints2(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->len > combi->p && combi->p != -1)
	{
		if (combi->zero == 0)
		{
			if ((dest = ft_malloc_space(combi->len)) == 0)
				return (ft_free(&toprint, 0));
		}
		else
		{
			if ((dest = ft_malloc_zero(combi->len)) == 0)
				return (ft_free(&toprint, 0));
		}
		if (combi->m == 1)
			while (toprint[i] != '\0' && i < combi->p)
				dest[n++] = toprint[i++];
		else
		{
			n = combi->len - combi->p;
			while (toprint[i] != '\0' && n < combi->len)
				dest[n++] = toprint[i++];
		}
	}
	else
		return (prints3(combi, toprint, i, n));
	ft_free(&toprint, 0);
	return (dest);
}

char	*prints(t_flag *combi, char *toprint, int i, int n)
{
	char	*dest;

	if (combi->len > combi->p && combi->p >= ft_strlen(toprint))
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
		n = (combi->m == 1) ? 0 : combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->p > ft_strlen(toprint) && combi->len < ft_strlen(toprint))
		return (toprint);
	else if (combi->p > combi->len && combi->len > ft_strlen(toprint))
	{
		if ((dest = printminlen(combi, toprint)) == 0)
			return (ft_free(&toprint, 0));
	}
	else
		return (prints2(combi, toprint, i, n));
	ft_free(&toprint, 0);
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
	{
		if ((toprint = ft_strdup("(null)")) == 0)
			return (0);
	}
	else
	{
		if ((toprint = ft_strdup((const char*)toprint)) == 0)
			return (0);
	}
	if (combi->p >= combi->len && combi->p <= ft_strlen(toprint))
	{
		if ((dest = ft_malloc_space(combi->p)) == 0)
			return (ft_free(&toprint, 0));
		while (i < combi->p)
		{
			dest[i] = toprint[i];
			i++;
		}
	}
	else
		return (prints(combi, toprint, i, n));
	ft_free(&toprint, 0);
	return (dest);
}
