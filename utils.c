/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:57:16 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 12:57:17 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malloc_space(int n)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(char) * n)))
		return (0);
	dest[n] = '\0';
	n--;
	while (n != -1)
	{
		dest[n] = ' ';
		n--;
	}
	return (dest);
}

char	*ft_malloc_zero(int n)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(char) * n)))
		return (0);
	dest[n] = '\0';
	n--;
	while (n != -1)
	{
		dest[n] = '0';
		n--;
	}
	return (dest);
}
