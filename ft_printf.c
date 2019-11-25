/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:41:08 by bminner           #+#    #+#             */
/*   Updated: 2019/11/14 09:41:09 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		find_format(va_list ap, char const *arg, int n)
{
	int ret;

	if (arg[n] == 'd' || arg[n] == 'i')
		ret = ft_putnbr(va_arg(ap, int));
	else if (arg[n] == 's')
		ret = ft_putstr(va_arg(ap, char*));
	else if (arg[n] == 'c')
		ret = ft_putchar(va_arg(ap, int));
	else if (arg[n] == 'u')
		ret = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (arg[n] == 'x')
		ret = convert_hexa(va_arg(ap, unsigned int));
	else if (arg[n] == 'X')
		ret = convert_hexa_maj(va_arg(ap, unsigned int));
	return (n);
}

int		ft_printf(char const *arg, ...)
{
	int			n;
	int			ret;
	va_list		ap;

	n = 0;
	ret = 0;
	va_start(ap, arg);
	while (arg[n] != '\0')
	{
		if (arg[n] == '%' && arg[n + 1] != '%')
		{
			n++;
			ret += find_format(ap, arg, n);
			n++;
		}
		else
		{
			write(1, &arg[n], 1);
			n++;
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}

int		main(void)
{
	char		i;

	i = 48;
	ft_printf("%X\n", i);
	printf("%%\n");
	return (0);
}
