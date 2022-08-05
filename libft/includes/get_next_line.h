#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_gnl_data
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;
}t_gnl_data;

typedef struct s_trim_data
{
	int		len;
	char	*line;
	char	*tmp;
}t_trim_data;

char	*get_next_line(int fd);
#endif
