/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:25 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:27 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cases2(t_flag *combi, char *toprint, int cas)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	if (cas == 1)
	{
		dest = ft_malloc_zero(combi->len);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (cas == 2)
	{
		dest = ft_malloc_space(combi->len);
		if (combi->moins == 0)
			n = combi->len - ft_strlen(toprint);
		else
			n = 0;
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*cases1(t_flag *combi, char *toprint, int cas)
{
	char	*dest;
	int		n;
	int		i;

	i = 0;
	if (cas == 1)
	{
		n = combi->precision - ft_strlen(toprint);
		dest = ft_malloc_zero(combi->precision);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (cas == 2)
	{
		if (combi->moins == 0)
			n = combi->len - combi->precision;
		else
			n = 0;
		dest = ft_malloc_space(combi->len);
		while (n < (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

int		ft_len_u(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dest;
	int		len;
	long	i;

	i = (long)n;
	len = ft_len_u(i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
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

char	*print_unsigned(t_flag *combi, unsigned num)
{
	char	*dest;
	char	*toprint;
	int		i;
	int		n;

	i = 0;
	toprint = ft_uitoa(num);
	if (combi->precision <= 0 && toprint[0] != '0')
		combi->precision = -1;
	if (toprint[0] == '0' && combi->precision == 0)
		dest = ft_malloc_space(combi->len);
	else if (combi->precision > combi->len && combi->precision > ft_strlen(toprint))
		dest = cases1(combi, toprint, 1);
	else if (combi->len > combi->precision && combi->precision > ft_strlen(toprint))
	{
		dest = ft_malloc_space(combi->len);
		if (combi->moins == 0)
		{
			n = combi->len - combi->precision;
			while (n < (combi->len - ft_strlen(toprint)))
				dest[n++] = '0';
		}
		else
		{
			n = 0;
			while (n < (combi->precision - ft_strlen(toprint)))
				dest[n++] = '0';
		}
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->zero == 1 && combi->precision < 0)
		dest = cases2(combi, toprint, 1);
	else if (combi->len > ft_strlen(toprint))
		dest = cases2(combi, toprint, 2);
	else
		dest = toprint;
	return (dest);
}
