/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:42 by bminner           #+#    #+#             */
/*   Updated: 2019/11/18 21:18:44 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(int nb)
{
	int ret;

	ret = 0;
	if (nb == -2147483648)
	{
		ret += ft_putchar('-');
		ret += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ret += ft_putnbr(nb / 10);
		ret += ft_putchar((nb % 10) + 48);
	}
	else
		ret += ft_putchar(nb + 48);
	return (ret);
}

int		ft_putnbr_unsigned(unsigned int nb)
{
	int ret;

	ret = 0;
	if (nb > 9)
	{
		ret += ft_putnbr(nb / 10);
		ret += ft_putchar((nb % 10) + 48);
	}
	else
		ret += ft_putchar(nb + 48);
	return (ret);
}

int		print_porcent(void)
{
	write(1, "%", 1);
	return (1);
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