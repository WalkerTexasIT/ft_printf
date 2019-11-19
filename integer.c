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

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_putnbr(int n)
{
	int ret;

	ret = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		ret++;
	}
	if (n == 0)
	{
		ft_putchar('0');
		ret++;
	}
	while (n > 0)
	{
		ft_putchar((n % 10) + 48);
		n /= 10;
		ret++;
	}
	return (ret);
}
