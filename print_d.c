/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:24:53 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:24:54 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dutils0(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->len > combi->p && combi->p != -1)
	{
		if ((dest = dutils4(combi, toprint, i, 0)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len > ft_strlen(toprint))
	{
		if (combi->m == 1)
		{
			n = 0;
			if ((dest = ft_malloc_space(combi->len)) == 0)
				return (ft_free(&toprint, 0));
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
		}
		else
		{
			if ((dest = dutils6(combi, toprint, i, n)) == 0)
				return (ft_free(&toprint, 0));
		}
	}
	return (dest);
}

char	*dutils(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->p >= combi->len && combi->p >= ft_strlen(toprint))
	{
		if ((dest = dutils1(combi, toprint, i, 0)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len >= combi->p && combi->p >= ft_strlen(toprint))
	{
		if ((dest = dutils2(combi, toprint, i, 0)) == 0)
			return (ft_free(&toprint, 0));
	}
	else
	{
		if ((dutils0(combi, toprint, i, n)) == 0)
			return (ft_free(&toprint, 0));
	}
	
	return (dest);
}

int		ft_len(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	i;

	i = (long)n;
	len = ft_len(i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	if (i < 0)
		dest[0] = '-';
	if (i < 0)
		i *= -1;
	if (i == 0)
		dest[0] = '0';
	while (i > 0)
	{
		dest[len - 1] = (i % 10) + 48;
		i /= 10;
		len--;
	}
	return (dest);
}

char	*print_integer(t_flag *combi, int num)
{
	char	*dest;
	char	*toprint;
	int		i;
	int		n;

	i = 0;
	if ((toprint = ft_itoa(num)) == 0)
		return (0);
	combi->p = (combi->p < 0 && toprint[0] != '0') ? -1 : combi->p;
	if (toprint[0] == '0' && combi->p == 0)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len > ft_strlen(toprint) || combi->p >= ft_strlen(toprint))
	{
		if ((dest = dutils(combi, toprint, i, n)) == 0)
			return (0);
	}
	else
		return (toprint);
	ft_free(&toprint, 0);
	return (dest);
}
