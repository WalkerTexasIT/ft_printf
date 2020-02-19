/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:25 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:27 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cases2(t_flag *combi, char *toprint, int cas)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	if (cas == 1)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (cas == 2)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
		if (combi->m == 0)
			n = combi->len - ft_strlen(toprint);
		else
			n = 0;
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*cases1(t_flag *combi, char *toprint, int cas)
{
	char	*dest;
	int		n;
	int		i;

	i = 0;
	if (cas == 1)
	{
		n = combi->p - ft_strlen(toprint);
		if ((dest = ft_malloc_zero(combi->p)) == 0)
			return (0);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (cas == 2)
	{
		if (combi->m == 0)
			n = combi->len - combi->p;
		else
			n = 0;
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
		while (n < (combi->len - ft_strlen(toprint)))
			dest[n++] = '0';
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

int		ft_len_u(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dest;
	int		len;
	long	i;

	i = (long)n;
	len = ft_len_u(i);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	if (i == 0)
		dest[0] = '0';
	while (i > 0)
	{
		dest[len - 1] = (i % 10) + 48;
		i /= 10;
		len--;
	}
	return (dest);
}

char	*print_unsigned(t_flag *combi, unsigned num)
{
	char	*dest;
	char	*toprint;
	int		i;
	int		n;

	i = 0;
	if ((toprint = ft_uitoa(num)) == 0)
		return (0);
	combi->p = (combi->p < 0 && toprint[0] != '0') ? -1 : combi->p;
	if (toprint[0] == '0' && combi->p == 0)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->p >= combi->len && combi->p > ft_strlen(toprint))
	{
		if ((dest = cases1(combi, toprint, 1)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len > combi->p && combi->p > ft_strlen(toprint))
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (ft_free(&toprint, 0));
		if (combi->m == 0)
		{
			n = combi->len - combi->p;
			while (n < (combi->len - ft_strlen(toprint)))
				dest[n++] = '0';
		}
		else
		{
			n = 0;
			while (n < (combi->p - ft_strlen(toprint)))
				dest[n++] = '0';
		}
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->zero == 1 && combi->p < 0 && combi->m != 1)
	{
		if ((dest = cases2(combi, toprint, 1)) == 0)
			return (ft_free(&toprint, 0));
	}
	else if (combi->len > ft_strlen(toprint))
	{
		if ((dest = cases2(combi, toprint, 2)) == 0)
			return (ft_free(&toprint, 0));
	}
	else
		return (toprint);
	ft_free(&toprint, 0);
	return (dest);
}
