#include "msh_commands.h"
#include "ft_printf.h"
t_bool	msh_env_path_cmd_search(t_minishel *msh, char **args)
{
	ft_printf("%s\n", ((t_env *)msh->env_start->content)->env + ((t_env *)msh->env_start->content)->index + 1);
	return (false);
}

t_bool	msh_full_path_cmd_search(t_minishel *msh, char **args)
{
	if (!access(*args, F_OK))
	{
		msh_fork_exec(msh, args);
		return (true);
	}
	return (false);
}

t_bool	msh_base_cmd_search(t_minishel *msh, char **args)
{
	size_t	i;
	
	i = -1;
	while (++i < MSH_CMD_SIZE)
		if (!ft_strcmp(*args, g_cmd_string[i]))
		{
			g_cmd_func[i](msh, args + 1);
			return (true);
		}
	return (false);
}
