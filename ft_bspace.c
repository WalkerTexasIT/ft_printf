#include "ft_printf.h"

void	*ft_calloc(size_t size)
{
	void	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * size)))
		return (0);
	ft_bzero(dest, size);
	return (dest);
}

void	ft_bspace(void *src, int n)
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

int		ft_strlen(char *src)
{
	int n;

	n = 0;
	while (src[n] != '\0')
		n++;
	return (n);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		n;
	char	*dest;

	n = 0;
	len = ((ft_strlen(s1)) + 1);
	if ((dest = ((char *)malloc(sizeof(char) * len))))
	{
		while (n < len)
		{
			dest[n] = (char)s1[n];
			n++;
		}
		return (dest);
	}
	return (0);
}
