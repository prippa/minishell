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

	ft_lstadd(&lst, ft_lstnew(NULL, 0));
	lst->content = str1;
	ft_lstadd(&lst, ft_lstnew(NULL, 0));
	lst->content = str2;
	ft_lstadd(&lst, ft_lstnew(NULL, 0));
	lst->content = str3;
	ft_lstiter(lst, print_list);
	return 0;
}

