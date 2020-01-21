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

char	*option1(t_flag *combi, char *toprint, int case)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	if (case == 1)
	{
		n = combi->len - ft_strlen(toprint);
		if (combi->zero = 1 && combi->precision == 0 && combi->moins == 0)
			dest = ft_malloc_zero(combi->len);
		else
			dest = ft_malloc_space(combi->len);
		if (combi->moins == 1)
			dest[i] = toprint[i++];
		else
			while (toprint[i] != '\0')
				dest[n++] = toprint[i++];
	}
	if (case == 2)
	return (dest);
}

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

char	*ft_hexatoa(unsigned int n)
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
		dest[len - 1] = ft_puthexa(i % 16);
		i /= 16;
		len--;
	}
	return (dest);
}

char	*print_hexa(t_flag *combi, unsigned int num)
{
	char	*dest;
	char	*toprint;

	toprint = ft_hexatoa(num);
	if (combi->len > combi->precision && combi->precision > ft_strlen(toprint))
		dest = option1(combi, toprint, 2);
	else if (combi->len > ft_strlen(toprint) && combi->precision == 0)
		dest = option1(combi, toprint, 1);
}