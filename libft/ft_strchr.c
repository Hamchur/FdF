#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] != (char)c)
		return (NULL);
	else
		return ((char *)s + i);
}
