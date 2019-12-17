/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:42 by bminner           #+#    #+#             */
/*   Updated: 2019/12/17 14:30:21 by bminner          ###   ########.fr       */
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

char	*aff_pointeur(unsigned long long i)
{
	char	*dest;
	int		len;

	len = ft_lenhexa((long long)i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 3))))
		return (0);
	len += 2;
	dest[0] = '0';
	dest[1] = 'x';
	dest[len] = '\0';
	if (i == 0)
		dest[2] = '0';
	while (i > 0)
	{
		dest[len - 1] = ft_puthexa(i % 16);
		i /= 16;
		len--;
	}
	return (dest);
}
