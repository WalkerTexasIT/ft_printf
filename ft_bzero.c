/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:59:04 by bminner           #+#    #+#             */
/*   Updated: 2020/01/13 10:55:50 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *src, int n)
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
