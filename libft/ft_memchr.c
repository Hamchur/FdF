#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
