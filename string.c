/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:59:23 by bminner           #+#    #+#             */
/*   Updated: 2019/11/19 14:59:25 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexa_maj(int n)
{
	if (0 <= n && n <= 9)
	{
		n += 48;
		write(1, &n, 1);
	}
	if (n == 10)
		write(1, "A", 1);
	if (n == 11)
		write(1, "B", 1);
	if (n == 12)
		write(1, "C", 1);
	if (n == 13)
		write(1, "D", 1);
	if (n == 14)
		write(1, "E", 1);
	if (n == 15)
		write(1, "F", 1);
	return (1);
}

int		ft_puthexa(int n)
{
	if (0 <= n && n <= 9)
	{
		n += 48;
		write(1, &n, 1);
	}
	if (n == 10)
		write(1, "a", 1);
	if (n == 11)
		write(1, "b", 1);
	if (n == 12)
		write(1, "c", 1);
	if (n == 13)
		write(1, "d", 1);
	if (n == 14)
		write(1, "e", 1);
	if (n == 15)
		write(1, "f", 1);
	return (1);
}

int		ft_putstr(char *str)
{
    int n;

    n = 0;
    while (str[n] != '\0')
    {
        write(1, &str[n], 1);
        n++;
    }
    return (n - 1);
}

int		convert_hexa(unsigned int nb)
{
	int ret;

	ret = 0;
	if (nb > 15)
	{
		ret += convert_hexa(nb / 16);
		ret += ft_puthexa(nb % 16);
	}
	else
		ret += ft_puthexa(nb);
	return (ret);
}

int		convert_hexa_maj(unsigned int nb)
{
	int ret;

	ret = 0;
	if (nb > 15)
	{
		ret += convert_hexa_maj(nb / 16);
		ret += ft_puthexa_maj(nb % 16);
	}
	else
		ret += ft_puthexa_maj(nb);
	return (ret);
}