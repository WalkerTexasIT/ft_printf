/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:25:13 by bminner           #+#    #+#             */
/*   Updated: 2020/01/16 11:25:15 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_string(t_flag *combi, char *toprint)
{
	char *dest;

	if (combi->precision != 0 && combi->precision < ft_strlen(toprint))
}