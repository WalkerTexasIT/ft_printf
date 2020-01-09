/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:38:18 by bminner           #+#    #+#             */
/*   Updated: 2020/01/09 15:21:17 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexa_maj(int n)
{

	if (0 <= n && n <= 9)
		return(n += 48);
	if (n == 10)
		return('A');
	if (n == 11)
		return('B');
	if (n == 12)
		return('C');
	if (n == 13)
		return('D');
	if (n == 14)
		return('E');
	if (n == 15)
		return('F');
	return(0);
}

int		ft_puthexa(int n)
{

	if (0 <= n && n <= 9)
		return(n += 48);
	if (n == 10)
		return('a');
	if (n == 11)
		return('b');
	if (n == 12)
		return('c');
	if (n == 13)
		return('d');
	if (n == 14)
		return('e');
	if (n == 15)
		return('f');
	return(0);
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

char	*ft_hexatoa_maj(unsigned int n, t_flag *combi)
{
	char	*dest;
	int		len;
	long	i;

	i = (long)n;
	len = ft_lenhexa((long long)i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	if (i == 0)
		dest[0] = '0';
	while (i > 0)
	{
		dest[len - 1] = ft_puthexa_maj(i % 16);
		i /= 16;
		len--;
	}
	combi->type = 'X';
	return (dest);
}

char	*ft_hexatoa(unsigned int n, t_flag *combi)
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
	combi->type = 'x';
	return (dest);
}
