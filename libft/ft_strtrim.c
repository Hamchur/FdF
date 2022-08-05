#include "includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	len_str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_str = ft_strlen(s1);
	while (len_str && ft_strchr(set, s1[len_str]))
		len_str--;
	new_str = ft_substr(s1, 0, len_str + 1);
	return (new_str);
}
