/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:45:38 by bminner           #+#    #+#             */
/*   Updated: 2020/03/02 16:45:39 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*xutils3(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (combi->len > ft_strlen(toprint) && combi->zero == 1
								&& combi->p == -1 && combi->m != 1)
	{
		if ((dest = ft_malloc_zero(combi->len)) == 0)
			return (0);
		n = combi->len - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else if (combi->len > ft_strlen(toprint) && combi->m == 1 && combi->p == -1)
	{
		if ((dest = ft_malloc_space(combi->len)) == 0)
			return (0);
		n = 0;
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}

char	*xutils2(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	n = combi->len - ft_strlen(toprint);
	if (combi->zero == 1 && combi->p == -1 && combi->m == 0)
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
		{
			dest[i] = toprint[i];
			i++;
		}
	else
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	return (dest);
}

char	*putils1(t_flag *combi, char *toprint, int j, int n)
{
	char *dest;

	if ((dest = ft_malloc_zero(combi->p + 2)) == 0)
		return (0);
	dest[0] = toprint[j++];
	dest[1] = toprint[j++];
	n = combi->p - ft_strlen(toprint) + 4;
	while (toprint[j] != '\0')
		dest[n++] = toprint[j++];
	return (dest);
}
