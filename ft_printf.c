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
	if (nbr(arg, n, combi) == 0)
		star_len(ap, arg, n, combi);
	if (verif(arg, n) == 1)
		return ;
	if (precision(arg, n, combi) == 1)
		if (nbr_pre(arg, n, combi) == 0)
			star_pres(ap, arg, n, combi);
	return ;
}

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
	if (arg[*n] == '%')
		dest = print_porcent(combi);
	else if (arg[*n] == 'c')
		dest = print_char(combi, va_arg(ap, int));
	else if (arg[*n] == 's')
		dest = print_string(combi, va_arg(ap, char*));
	/*if (arg[*n] == 'd' || arg[*n] == 'i')
		dest = ft_itoa(va_arg(ap, int), combi);
	else if (arg[*n] == 's')
	{
		dest = va_arg(ap, char*);
		combi->type = 's';
	}
	else if (arg[*n] == 'c')
		dest = ft_putchar(va_arg(ap, int), combi);
	else if (arg[*n] == 'u')
		dest = ft_itoa_unsigned(va_arg(ap, unsigned int), combi);
	else if (arg[*n] == 'x')
		dest = ft_hexatoa(va_arg(ap, unsigned int), combi);
	else if (arg[*n] == 'X')
		dest = ft_hexatoa_maj(va_arg(ap, unsigned int), combi);
	else if (arg[*n] == '%')
		dest = print_porcent(combi);
	else if (arg[*n] == 'p')
		dest = aff_pointeur(va_arg(ap, unsigned long long), combi);*/
	else
		printf("error by %c\n", arg[*n]);
	return (printstring(dest));
}

int		combi(va_list ap, char const *arg, int *n)
{
	t_flag	combi;

	combi.zero = 0;
	combi.moins = 0;
	combi.precision = 0;
	combi.len = 0;
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
	ft_printf("%send\n", "salut");
	printf("%send\n", "salut");
}
