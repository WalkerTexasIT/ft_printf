/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:59:04 by bminner           #+#    #+#             */
/*   Updated: 2019/10/08 13:59:06 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *src, size_t n)
{
	char *char_src;

	if (src == 0)
		return ;
	char_src = (char *)src;
	while (n != 0)
	{
		*char_src = '0';
		char_src++;
		n--;
	}
}
