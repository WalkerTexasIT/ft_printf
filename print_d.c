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

char	*case2(t_flag *combi, char *toprint, int cas)
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
	return (dest);
}

char	*case1(t_flag *combi, char *toprint, int cas)
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
		dest = ft_malloc_space(combi->len);
		n = combi->len - combi->precision;
		while (n < (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
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

	toprint = ft_itoa(num);
	if (combi->precision > combi->len && combi->precision > ft_strlen(toprint))
		dest = case1(combi, toprint, 1);
	else if (combi->len > combi->precision && combi->precision > ft_strlen(toprint))
		dest = case1(combi, toprint, 2);
	else if (combi->len > ft_strlen(toprint) && combi->zero == 1)
		dest = case2(combi, toprint, 1);
	else
		dest = toprint;
	return (dest);
}