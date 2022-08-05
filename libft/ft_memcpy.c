#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (n)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	return (dst);
}
