/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:19:41 by bminner           #+#    #+#             */
/*   Updated: 2020/02/19 15:19:43 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free(char **tofree, int ret)
{
	if (*tofree)
	{
		free(*tofree);
		*tofree = 0;
	}
	return (0);
}

int		ft_free_retint(char **tofree, int ret)
{
	if (*tofree)
	{
		free(*tofree);
		*tofree = 0;
	}
	return (0);
}
