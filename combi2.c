#include "ft_printf.h"

char	*debut(char *dest, char *string, t_flag *combi)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		dest[i] = string[i];
		i++;
		combi->precision--;
	}
	while (combi->precision != 0)
	{
		dest[i] = '0';
		i++;
		combi->precision--;
	}
	return (dest);
}
