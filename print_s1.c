/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:43:03 by bminner           #+#    #+#             */
/*   Updated: 2020/03/02 17:43:04 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prints4(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if ((dest = ft_malloc_space(combi->p)) == 0)
		return (0);
	while (i < combi->p)
	{
		dest[i] = toprint[i];
		i++;
	}
	return (dest);
}

char	*printlen(t_flag *combi, char *toprint, int n)
{
	char	*dest;
	int		i;

	i = 0;
	if (combi->zero == 1 && combi->m == 0)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
	}
	else
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
	}
	if (combi->m == 1)
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	else
	{
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}
