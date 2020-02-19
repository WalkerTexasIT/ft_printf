/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:16:39 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 09:16:42 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check(va_list ap, char const *arg, int *n, t_flag *combi)
{
	moins(arg, n, combi);
	zero(arg, n, combi);
	moins(arg, n, combi);
	if (nbr(arg, n, combi) == 0)
		star_len(ap, arg, n, combi);
	if (precision(arg, n, combi) == 1)
		if (nbr_pre(arg, n, combi) == 0 && arg[*n] == '*')
			star_pres(ap, arg, n, combi);
	return ;
}

int		printstring(t_flag *combi, char *dest)
{
	int n;

	n = 0;
	while (dest[n] != '\0' || (dest[n] == '\0' && combi->iszero == 1))
	{
		if (dest[n] == '\0')
		{
			combi->iszero--;
			write(1, "\0", 1);
		}
		else
			write(1, &dest[n], 1);
		n++;
	}
	ft_free(&dest, 0);
	return (n - 1);
}

int		find_format(va_list ap, char const *arg, int *n, t_flag *combi)
{
	char *dest;

	check(ap, arg, n, combi);
	if (verif(arg, n) == 0)
	{
		(*n)--;
		return (0);
	}
	if (arg[*n] == '%')
		if ((dest = print_porcent(combi)) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'c')
		if ((dest = print_char(combi, va_arg(ap, int))) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 's')
		if ((dest = print_string(combi, va_arg(ap, char*))) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'd' || arg[*n] == 'i')
		if ((dest = print_integer(combi, va_arg(ap, int))) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'u')
		if ((dest = print_unsigned(combi, va_arg(ap, unsigned int))) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'x')
		if ((dest = print_hexa(combi, va_arg(ap, unsigned int), 1)) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'X')
		if ((dest = print_hexa(combi, va_arg(ap, unsigned int), 2)) == 0)
			return (ft_free(&dest, -1));
	else if (arg[*n] == 'p')
		if ((dest = print_pointer(combi, va_arg(ap, unsigned long long))) == 0)
			return (ft_free(&dest, -1));
	return (printstring(combi, dest));
}

int		combi(va_list ap, char const *arg, int *n)
{
	t_flag	combi;

	combi.zero = 0;
	combi.moins = 0;
	combi.precision = -1;
	combi.len = 0;
	combi.iszero = 0;
	return (find_format(ap, arg, n, &combi));
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
			write(1, &arg[n++], 1);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
