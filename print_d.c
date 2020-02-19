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

char	*dutils4(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	dest = ft_malloc_space(combi->len);
	if (combi->moins == 1)
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

	n = combi->len - combi->precision;
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

	dest = ft_malloc_space(combi->len);
	if (combi->moins == 1)
	{
		n = 0;
		if (toprint[0] == '-')
			dest[n++] = toprint[i++];
		if (toprint[0] == '-')
			while (n <= (combi->precision - ft_strlen(toprint) + 1))
				dest[n++] = '0';
		else
			while (n < (combi->precision - ft_strlen(toprint)))
				dest[n++] = '0';
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		n = combi->len - combi->precision;
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
	}
	return (dest);
}

char	*dutils1(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (toprint[0] == '-')
	{
		dest = ft_malloc_zero(combi->precision + 1);
		n = combi->precision - ft_strlen(toprint) + 2;
		dest[0] = toprint[i++];
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		dest = ft_malloc_zero(combi->precision);
		n = combi->precision - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
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
	if (combi->precision < 0 && toprint[0] != '0')
		combi->precision = -1;
	if (toprint[0] == '0' && combi->precision == 0)
		dest = ft_malloc_space(combi->len);
	else if (combi->len > ft_strlen(toprint) || combi->precision >= ft_strlen(toprint))
	{
		if (combi->precision >= combi->len && combi->precision >= ft_strlen(toprint))
			dest = dutils1(combi, toprint, i, 0);
		else if (combi->len >= combi->precision && combi->precision >= ft_strlen(toprint))
			dest = dutils2(combi, toprint, i, 0);
		else if (combi->len > combi->precision && combi->precision != -1)
			dest = dutils4(combi, toprint, i, 0);
		else if (combi->len > ft_strlen(toprint))
		{
			if (combi->moins == 1)
			{
				n = 0;
				dest = ft_malloc_space(combi->len);
				while (toprint[i] != '\0')
					dest[n++] = toprint[i++];
			}
			else
			{
				if (combi->zero == 1)
				{
					dest = ft_malloc_zero(combi->len);
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
					dest = ft_malloc_space(combi->len);
					n = combi->len - ft_strlen(toprint);
					while (toprint[i] != '\0')
						dest[n++] = toprint[i++];
				}
			}
		}
	}
	else
		return (toprint);
	free(toprint);
	return (dest);
}
