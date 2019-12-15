/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:46:47 by bminner           #+#    #+#             */
/*   Updated: 2019/12/13 13:46:48 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	moins(char const *arg, int *n, flag *combi)
{
    if (arg[*n] == '-')
    {
        combi->moins = 1;
        *n++;
    }
}

void	zero(char const *arg, int *n, flag *combi)
{
	if (arg[*n] == '0')
	{
		combi->zero = 0;
		*n++;
	}
}

void	point(char const *arg, int *n, flag *combi)
{
	if (arg[*n] == '.')
	{
		combi->point = 1;
		*n++;
	}
}

void	star(char const *arg, int *n, flag *combi)
{
	if (arg[*n] == '*')
	{
		combi->star = 1;
		*n++;
	}
}

void	nbr(char const *arg, int *n, flag *combi)
{
	char	*list;
	int		i;

	i = 0;
	list = "123456789";
	while (list[i] != '\0')
	{
		if (arg[*n] == list[i])
			break ;
		i++;
	}
	
}