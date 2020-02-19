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

int		ft_strlen(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int		ft_lenhexa(long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		n;
	char	*dest;

	n = 0;
	len = ((ft_strlen(s1)) + 1);
	if ((dest = ((char *)malloc(sizeof(char) * len))))
	{
		while (n < len)
		{
			dest[n] = (char)s1[n];
			n++;
		}
		return (dest);
	}
	return (0);
}
