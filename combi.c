/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:20:17 by bminner           #+#    #+#             */
/*   Updated: 2019/12/11 11:20:19 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero(char const *arg, int *n, flag *combi)
{
	if (arg[*n] == '0')
	{
		combi->zero = 1;
		*n++;
	}
}

int		verif(char const *arg, int *n)
{
	
}

void	combi(char const *arg, int *n)
{
	t_flag combi;
	int		n;

	n = 0;
	combi.zero = 0;
	combi.moins = 0;
	combi.point = 0;
	combi.star = 0;
	combi.nbr = 1;
	zero(arg, n, &combi);
	if (verif(arg, n) == 0)
		n = 1;
}