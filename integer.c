/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:42 by bminner           #+#    #+#             */
/*   Updated: 2020/01/09 15:22:53 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar(char c, t_flag *combi)
{
	char *dest;

	if (!(dest = malloc(sizeof(char))))
		return (0);
	dest[0] = c;
	dest[1] = '\0';
	combi->type = 'c';
	return (dest);
}

char	*print_porcent(t_flag *combi)
{
	combi->type = '%';
	return (ft_strdup("%"));
}

char	*aff_pointeur(unsigned long long i, t_flag *combi)
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
	combi->type = 'p';
	return (dest);
}
