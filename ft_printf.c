/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:41:08 by bminner           #+#    #+#             */
/*   Updated: 2020/01/06 09:17:10 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		printstring(char *dest)
{
	int n;

	n = 0;
	while (dest[n] != '\0')
	{
		write(1, &dest[n], 1);
		n++;
	}
	return (n - 1);
}

int		find_format(va_list ap, char const *arg, int *n, t_flag *combi)
{
	char *dest;

	check(ap, arg, n, combi);
	if (arg[*n] == 'd' || arg[*n] == 'i')
		dest = ft_itoa(va_arg(ap, int));
	else if (arg[*n] == 's')
		dest = va_arg(ap, char*);
	else if (arg[*n] == 'c')
		dest = ft_putchar(va_arg(ap, int));
	else if (arg[*n] == 'u')
		dest = ft_itoa_unsigned(va_arg(ap, unsigned int));
	else if (arg[*n] == 'x')
		dest = ft_hexatoa(va_arg(ap, unsigned int));
	else if (arg[*n] == 'X')
		dest = ft_hexatoa_maj(va_arg(ap, unsigned int));
	else if (arg[*n] == '%')
		dest = print_porcent();
	else if (arg[*n] == 'p')
		dest = aff_pointeur(va_arg(ap, unsigned long long));
	return (printstring(dest));
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
		if (arg[n] == '%')
		{
			n++;
			ret += combi(ap, arg, &n);
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
	unsigned int		i;

	i = 1351654646;
	//ft_printf("%%\n");
	printf("%.*d\n", 10, 2);
	return (0);
}
