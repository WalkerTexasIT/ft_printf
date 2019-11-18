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

int		print(va_list ap, char const *arg)
{
	int n;
	int r;

	n = 0;
	r = 0;
	while (arg[n] != '\0')
	{
		if (arg[n] == '%')
		{
			//r += find_flag(ap, arg, r, n);
			n++;
		}
		else
		{
			write(1, arg[n], 1);
			r++;
		}
		n++;
	}
	return (r);
}

int		ft_printf(char const *arg, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, arg);

	ret = print(ap, arg);

	va_end(ap);
	return (ret);
}
