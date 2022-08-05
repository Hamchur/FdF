#include "includes/libft.h"

void	ft_print_reverse_list(t_list *list)
{
	if (list)
	{
		ft_print_reverse_list(list->next);
		ft_putendl_fd(list->content, 1);
	}
}
