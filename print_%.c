/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:24:25 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:24:26 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_porcent(t_flag *combi)
{
	char *dest;

	if (combi->len > 0)
	{
		if (combi->zero == 1 && combi->m == 0)
		{
			if ((dest = ft_malloc_zero(combi->len)) == 0)
				return (0);
		}
		else
			if ((dest = ft_malloc_space(combi->len)) == 0)
				return (0);
	}
	else
	{
		if ((dest = ft_malloc_space(1)) == 0)
			return (0);
	}
	if (combi->m == 1 || combi->len == 0)
		dest[0] = '%';
	else
		dest[combi->len - 1] = '%';
	return (dest);
}
