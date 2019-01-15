#include "libft/includes/libft.h"
#include <string.h>

#define SIZE 4096

void free_list(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void print_list(t_list *elem)
{
	char *str = (char *)elem->content;
	ft_printf("%s\n", str);
}

int main(int argc, char const *argv[])
{
	t_list *lst;
	char *str1 = ft_strdup("String one");
	char *str2 = ft_strdup("String two");
	char *str3 = ft_strdup("1234");

	ft_lstadd(&lst, ft_lstnew(str1, 0));
	ft_lstadd(&lst, ft_lstnew(str2, 0));
	ft_lstadd(&lst, ft_lstnew(str3, 0));
	ft_lstiter(lst, print_list);
	ft_lstdel(&lst, NULL);
	ft_lstadd(&lst, ft_lstnew(str3, 0));
	ft_lstadd(&lst, ft_lstnew(str2, 0));
	ft_lstadd(&lst, ft_lstnew(str1, 0));
	ft_lstiter(lst, print_list);
	ft_lstdel(&lst, NULL);
	system("leaks -q a.out");
	return 0;
}

