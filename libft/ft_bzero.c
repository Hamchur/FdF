#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = '\0';
		i++;
		n--;
	}
}
