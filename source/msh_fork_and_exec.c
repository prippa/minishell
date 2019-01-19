#include "minishell.h"

static char	**msh_env_convert_from_list_char(t_minishel *msh)
{
	char		**env;
	t_list2		*env_start;
	uint32_t	i;

	if (!(env = (char **)malloc(sizeof(char *) * (msh->env_size + 1))))
		msh_error_exit(msh, MALLOC_ERR);
	env[msh->env_size] = NULL;
	env_start = msh->env_start;
	i = -1;
	while (env_start)
	{
		env[++i] = ((t_env *)env_start->content)->env;
		env_start = env_start->next;
	}
	return (env);
}

void		msh_fork_exec(t_minishel *msh,
				const char *path, const char **args)
{
	char	**env;

	env = msh_env_convert_from_list_char(msh);
	
	free(env);
}
