/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:22:00 by bminner           #+#    #+#             */
/*   Updated: 2020/01/13 10:23:37 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("%s\n", "%0155.7d%--125.28d ,-591327463,-154910566");
	ft_printf("|%0155.7d|\n|%--125.28d|\n\n" ,-591327463,-154910566);
	printf("|%0155.7d|\n|%--125.28d|\n" ,-591327463,-154910566);
	//printf("\n|%5.3d|\n\n", -11);
	return (0);
}
