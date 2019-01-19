#include "msh_commands.h"

#define MSH_PATH_ENV "PATH"
#define MSH_PATH_ENV_SEPARATOR ':'

static t_bool	msh_make_full_path(t_minishel *msh,
					const char *path, const char **args)
{
	char	*full_path;
	t_bool	ny_cho_tam;

	if (!(full_path = ft_strnew(ft_strlen(path) + ft_strlen(*args) + 1)))
		msh_error_exit(msh, MALLOC_ERR);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, *args);
	ny_cho_tam = msh_full_path_cmd_search(msh, full_path, args);
	ft_strdel(&full_path);
	return (ny_cho_tam);
}

t_bool			msh_env_path_cmd_search(t_minishel *msh,
					const char **args)
{
	const char	*path_value;
	char		**paths;
	uint32_t	i;

	if ((path_value = msh_env_get_arg_by_name(msh->env_start, MSH_PATH_ENV,
		ft_strlen(MSH_PATH_ENV))))
	{
		if (!(paths = ft_strsplit(path_value, MSH_PATH_ENV_SEPARATOR)))
			msh_error_exit(msh, MALLOC_ERR);
		i = -1;
		while (paths[++i])
			if (msh_make_full_path(msh, paths[i], args))
			{
				ft_arrdel(&paths);
				return (true);
			}
		ft_arrdel(&paths);
	}
	return (false);
}

t_bool			msh_full_path_cmd_search(t_minishel *msh,
					const char *full_path, const char **args)
{
	if (!access(full_path, F_OK))
	{
		msh_fork_exec(msh, full_path, args);
		return (true);
	}
	return (false);
}

t_bool			msh_base_cmd_search(t_minishel *msh, const char **args)
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