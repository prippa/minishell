#include "libft/includes/libft.h"
#include <string.h>

#define SIZE 4096

typedef struct		s_s
{
	char			**arr;
}					t_s;

void free_list(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void print_list(t_list *elem)
{
	t_s *s;

	s = (t_s *)elem->content;
	ft_putarr(s->arr);
}

int main(int argc, char const *argv[])
{
	t_list *lst;
	t_s obj1;
	t_s obj2;
	t_s obj3;

	obj1.arr = ft_arrnew(2, 2, '1');
	ft_lstadd(&lst, ft_lstnew(&obj1, 0));
	obj2.arr = ft_arrnew(2, 2, '2');
	ft_lstadd(&lst, ft_lstnew(&obj2, 0));
	obj3.arr = ft_arrnew(2, 2, '3');
	ft_lstadd(&lst, ft_lstnew(&obj3, 0));
	ft_lstiter(lst, print_list);
	system("leaks -q a.out");
	return 0;
}

