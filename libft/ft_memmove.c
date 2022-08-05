#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*use_src;
	char	*use_dst;
	size_t	i;

	if (src == dst)
		return (dst);
	use_src = (char *)src;
	use_dst = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			use_dst[i] = use_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			use_dst[i] = use_src[i];
			i++;
		}
	}
	return (dst);
}
