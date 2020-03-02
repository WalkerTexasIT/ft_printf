/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:21:38 by bminner           #+#    #+#             */
/*   Updated: 2020/03/02 17:21:51 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*uutils1(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if ((dest = ft_malloc_space(combi->len)) == 0)
		return (0);
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
	return (dest);
}

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
