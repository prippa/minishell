#include "minishell.h"

t_env	*msh_env_get_obj_by_name(t_list2 *start, const char *name)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (!ft_strcmp(e->name, name))
			return (e);
		start = start->next;
	}
	return (NULL);
}

char	*msh_env_get_arg_by_name(t_list2 *start, const char *name)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (!ft_strcmp(e->name, name))
			return (e->arg);
		start = start->next;
	}
	return (NULL);
}