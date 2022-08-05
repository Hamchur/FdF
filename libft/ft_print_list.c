#include "includes/libft.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putendl_fd(list->content, 1);
		list = list->next;
	}
}
