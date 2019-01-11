#include "minishell.h"

t_list2	*msh_env_get_obj_by_name(t_list2 *start, const char *value)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (!ft_strncmp(e->value, value, e->index))
			return (start);
		start = start->next;
	}
	return (NULL);
}

char	*msh_env_get_arg_by_name(t_list2 *start, const char *value)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (!ft_strncmp(e->value, value, e->index))
			return (e->value + e->index);
		start = start->next;
	}
	return (NULL);
}