/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:03 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:04 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*first(t_flag *combi, char *toprint)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!(dest = ft_malloc_space(combi->len)))
		return (0);
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

int		ft_lenpointer(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_pointertoa(unsigned long long i)
{
	char	*dest;
	int		len;

	len = ft_lenpointer(i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 3))))
		return (0);
	len += 2;
	dest[0] = '0';
	dest[1] = 'x';
	dest[len] = '\0';
	if (i == 0)
		dest[0] = '0';
	while (i > 0)
	{
		dest[len - 1] = ft_puthexa(i % 16);
		i /= 16;
		len--;
	}
	return (dest);
}

char	*print_pointer(t_flag *combi, unsigned long long i)
{
	char *dest;
	char *toprint;
	int		j;
	int		n;

	j = 0;
	if (i == 0 && combi->p == -1)
	{
		if ((toprint = ft_malloc_zero(2)) == 0)
			return (0);
		toprint[0] = '0';
		toprint[1] = 'x';
		toprint[2] = '0';
	}
	else if (i == 0)
	{
		if ((toprint = ft_malloc_zero(combi->p + 2)) == 0)
			return (ft_free(&toprint, 0));
		toprint[0] = '0';
		toprint[1] = 'x';
	}
	else
		if ((toprint = ft_pointertoa(i)) == 0)
			return (0);
	if (combi->p > ft_strlen(toprint) && i != 0 && combi->p > combi->len)
	{
		if ((dest = ft_malloc_zero(combi->p + 2)) == 0)
			return (ft_free(&toprint, 0));
		dest[0] = toprint[j++];
		dest[1] = toprint[j++];
		n = combi->p - ft_strlen(toprint) + 4;
		while (toprint[j] != '\0')
			dest[n++] = toprint[j++];
	}
	else if (combi->len > ft_strlen(toprint))
	{
		if ((dest = first(combi, toprint)) == 0)
			return (ft_free(&toprint, 0));
	}
	else
		return (toprint);
	ft_free(&toprint, 0);
	return (dest);
}