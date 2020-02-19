/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:34 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:35 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexa(int n)
{
	if (0 <= n && n <= 9)
		return (n += 48);
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (0);
}

char	*ft_hexatoa(unsigned int n, int k)
{
	char	*dest;
	int		len;
	long	i;

	i = (long)n;
	len = ft_lenhexa(i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	if (i == 0)
		dest[0] = '0';
	while (i > 0)
	{
		if (k == 1)
			dest[len - 1] = ft_puthexa(i % 16);
		else
			dest[len - 1] = ft_puthexa_maj(i % 16);
		i /= 16;
		len--;
	}
	return (dest);
}

char	*print_hexa(t_flag *combi, unsigned int num, int maj)
{
	char	*dest;
	char	*toprint;
	int		i;
	int		n;

	i = 0;
	if ((toprint = ft_hexatoa(num, maj)) == 0)
		return (0);
	if (combi->p < 0 && toprint[0] != '0')
		combi->p = -1;
	if (toprint[0] == '0' && combi->p == 0)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len > combi->p && combi->p > ft_strlen(toprint))
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
		if (combi->m == 1)
		{
			n = 0;
			while (n < (combi->p - ft_strlen(toprint)))
				dest[n++] = '0';
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
		}
		else
		{
			n = combi->len - combi->p;
			while (n < (combi->len - ft_strlen(toprint)))
				dest[n++] = '0';
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
		}
	}
	else if (combi->p > ft_strlen(toprint))
	{
		if ((dest = ft_malloc_zero(combi->p)) == 0)
			return (ft_free(&toprint, 0));
		n = combi->p - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->zero == 1 && combi->p == -1 && combi->m != 1)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (ft_free(&toprint, 0));
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->m == 1 && combi->p == -1)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
		n = 0;
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->p <= ft_strlen(toprint))
	{
		n = combi->len - ft_strlen(toprint);
		if (combi->zero == 1 && combi->p == -1 && combi->m == 0)
		{
			if ((dest = ft_malloc_zero(combi->len)) == 0)
				return (ft_free(&toprint, 0));
		}
		else
		{
			if ((dest = ft_malloc_space(combi->len)) == 0)
				return (ft_free(&toprint, 0));
		}
		if (combi->m == 1)
			while (toprint[i] != '\0')
			{
				dest[i] = toprint[i];
				i++;
			}
		else
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
	}
	else
		return (toprint);
	ft_free(&toprint, 0);
	return (dest);
}