#include "includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, size * count);
	return ((void *)ret);
}
