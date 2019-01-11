#include "minishell.h"

void		msh_line_parser(t_msh *msh)
{
	char	**arr;
	size_t	i;
	t_list2	*start;

	arr = (char **)malloc(sizeof(char *) * msh->env_size + 1);
	i = -1;
	start = msh->env_start;
	while (++i < msh->env_size)
	{
		arr[i] = ((t_env *)start->content)->value;
		start = start->next;
	}
	arr[i] = NULL;
	ft_putarr(arr);
	free(arr);
	ft_printf("%s\n", msh->line);
}
