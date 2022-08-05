#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	if (len == 0)
		return (str);
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
