/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:48:04 by bminner           #+#    #+#             */
/*   Updated: 2020/03/02 15:48:06 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dutils6(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->zero == 1)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
		n = combi->len - ft_strlen(toprint);
		if (toprint[0] == '-')
		{
			dest[0] = toprint[i++];
			n++;
		}
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*dutils5(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if ((dest = ft_malloc_space(combi->len)) == 0)
		return (0);
	n = combi->len - combi->p;
	if (toprint[0] == '-')
		dest[n - 1] = toprint[i++];
	if (toprint[0] != '-')
		while (n < (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
	else
		while (n <= (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
	while (toprint[i] != '\0')
		dest[n++] = toprint[i++];
	return (dest);
}

char	*dutils4(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if ((dest = ft_malloc_space(combi->len)) == 0)
		return (0);
	if (combi->m == 1)
	{
		n = 0;
		if (toprint[0] == '-')
			dest[n++] = toprint[i++];
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		n = combi->len - ft_strlen(toprint);
		if (toprint[0] == '-')
			dest[n++] = toprint[i++];
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*dutils3(t_flag *combi, char *toprint, int i, char *dest)
{
	int n;

	n = combi->len - combi->p;
	if (toprint[0] == '-')
		dest[n - 1] = toprint[i++];
	if (toprint[0] != '-')
		while (n < (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
	else
		while (n <= (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
	while (toprint[i] != '\0')
		dest[n++] = toprint[i++];
	return (dest);
}

char	*dutils2(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->m == 1)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
		n = 0;
		if (toprint[0] == '-')
			dest[n++] = toprint[i++];
		if (toprint[0] == '-')
			while (n <= (combi->p - ft_strlen(toprint) + 1))
				dest[n++] = '0';
		else
			while (n < (combi->p - ft_strlen(toprint)))
				dest[n++] = '0';
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		if ((dest = dutils5(combi, toprint, i, n)) == 0)
			return (0);
	}
	return (dest);
}
