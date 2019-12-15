/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:42 by bminner           #+#    #+#             */
/*   Updated: 2019/12/15 15:42:13 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar(char c)
{
	char *dest;

	if (!(dest = malloc(sizeof(char))))
		return (0);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}

char	*print_porcent(void)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char))))
		return (0);
	dest[0] = '%';
	dest[1] = '\0';
	return (dest);
}

int		aff_pointeur(unsigned long long n, int i)
{
	int ret;

	ret = 0;
	if (i == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		ret += 2;
	}
	if (n > 15)
	{
		ret += aff_pointeur((n / 16), 1);
		ret += ft_puthexa(n % 16);
	}
	else
		ret += ft_puthexa(n);
	return (ret);
}
