/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:41:08 by bminner           #+#    #+#             */
/*   Updated: 2019/12/15 16:51:38 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		find_format(va_list ap, char const *arg, int *n)
{
	char *dest;

	if (arg[*n] == 'd' || arg[*n] == 'i')
		dest = ft_itoa(va_arg(ap, int));
	else if (arg[*n] == 's')
		dest = va_arg(ap, char*);
	else if (arg[*n] == 'c')
		dest = ft_char(va_arg(ap, int));
	else if (arg[*n] == 'u')
		dest = ft_itoa_unsigned(va_arg(ap, unsigned int));
	else if (arg[*n] == 'x')
		dest = convert_hexa(va_arg(ap, unsigned int));
	else if (arg[*n] == 'X')
		dest = convert_hexa_maj(va_arg(ap, unsigned int));
	else if (arg[*n] == '%')
		dest = print_porcent();
	else if (arg[*n] == 'p')
		dest = aff_pointeur(va_arg(ap, unsigned long long), 0);
	return (dest);
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
			ret += find_format(ap, arg, &n);
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
	char		*i;

	i = "34567";
	//ft_printf("rghzg%p\n", &i);
	printf("%*.5i/\n", 5, 2555555);
	return (0);
}
