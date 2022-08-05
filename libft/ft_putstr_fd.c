#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd((char)s[i], fd);
		i++;
	}
}
