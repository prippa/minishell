#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# define BUFF_SIZE	80

typedef	struct		s_gnl
{
	char			*s;
	size_t			i;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
