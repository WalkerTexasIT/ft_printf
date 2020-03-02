/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:57:46 by bminner           #+#    #+#             */
/*   Updated: 2020/03/02 15:58:01 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dutils1(t_flag *combi, char *toprint, int i, int n)
{
	char *dest;

	if (toprint[0] == '-')
	{
		if ((dest = ft_malloc_zero(combi->p + 1)) == 0)
			return (0);
		n = combi->p - ft_strlen(toprint) + 2;
		dest[0] = toprint[i++];
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	else
	{
		if ((dest = ft_malloc_zero(combi->p)) == 0)
			return (0);
		n = combi->p - ft_strlen(toprint);
		while (toprint[i] != '\0')
			dest[n++] = toprint[i++];
	}
	return (dest);
}
