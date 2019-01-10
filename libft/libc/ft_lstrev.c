#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	prev = NULL;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}

void	ft_lst2rev(t_list2 **start, t_list2 **end)
{
	t_list2 *current;
	t_list2 *prev;
	t_list2 *next;

	prev = NULL;
	current = *end;
	while (current)
	{
		next = current->prev;
		current->prev = prev;
		prev = current;
		current = next;
	}
	*end = prev;
	ft_lstrev((t_list **)start);
}
