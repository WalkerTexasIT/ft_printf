#include "ft_printf.h"

char	*debut(char *lon, char *string, t_flag *combi)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	n = 0;
	dest = lon;
	if (combi->precision > 0)
		combi->precision -= ft_strlen(string);
	while (combi->precision > 0)
	{
		dest[i] = '0';
		i++;
		combi->precision--;
	}
	while (string[n] != '\0')
	{
		dest[i] = string[n];
		i++;
		n++;
		combi->len--;
	}
	return (dest);
}

char	*fin(char *lon, char *string, t_flag *combi)
{
	char	*dest;
	int i;

	dest = lon;
	i = ft_strlen(string);
	printf("%d\n", combi->precision);
	if (combi->precision == 0)
		combi->precision = ft_strlen(string);
	while (i != -1 && combi->precision > 0)
	{
		dest[combi->len] = string[i];
		i--;
		combi->len--;
		combi->precision--;
	}
	while (combi->precision > 0)
	{
		dest[combi->len] = '0';
		combi->len--;
		combi->precision--;
	}
	return (dest);
}
