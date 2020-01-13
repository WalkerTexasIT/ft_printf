#include "ft_printf.h"

void	ft_bspace(void *src, size_t n)
{
	char *char_src;

	if (src == 0)
		return ;
	char_src = (char *)src;
	while (n != 0)
	{
		*char_src = ' ';
		char_src++;
		n--;
	}
}
