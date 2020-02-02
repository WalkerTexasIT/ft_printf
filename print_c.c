/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:24:44 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:24:45 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(t_flag *combi, char toprint)
{
	char *dest;

	if (toprint == 0)
		combi->iszero = 1;
	if (combi->len > 0)
		if (combi->zero == 1 && combi->moins == 0)
			dest = ft_malloc_zero(combi->len);
		else
			dest = ft_malloc_space(combi->len);
	else
		dest = ft_malloc_space(1);
	if (combi->moins == 1 || combi->len == 0)
		dest[0] = toprint;
	else
		dest[combi->len - 1] = toprint;
	return (dest);
}
