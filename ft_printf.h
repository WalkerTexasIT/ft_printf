/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by bminner           #+#    #+#             */
/*   Updated: 2019/11/14 14:12:49 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			ft_printf(const char *arg, ...);
int			ft_putnbr (int n);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr_unsigned(unsigned int nb);
int			convert_hexa(unsigned int nb);
int			convert_hexa_maj(unsigned int nb);

#endif
