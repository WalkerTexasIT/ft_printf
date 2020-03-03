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

int		parser(va_list ap, char const *arg)
{
	int		ret;
	int		retbuff;
	int		n;

	n = 0;
	ret = 0;
	while (arg[n] != '\0')
	{
		if (arg[n] == '%')
		{
			n++;
			if ((retbuff = combi(ap, arg, &n)) == -1)
				return (-1);
			ret += retbuff;
			n++;
		}
		else
		{
			write(1, &arg[n++], 1);
			ret++;
		}
	}
	return (ret);
}
