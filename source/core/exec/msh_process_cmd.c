/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:32 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "messages.h"

#define MSH_CMD_NOT_FOUND	SHELL_NAME ": %s: command not found"
#define MSH_CMD_SIZE		6

typedef void		(*t_func_cmd)(char **args);
static const		t_func_cmd	g_cmd_func[MSH_CMD_SIZE] =
{
	msh_cd, msh_echo, msh_env, msh_setenv,
	msh_unsetenv, msh_exit
};

static const char	*g_cmd_string[MSH_CMD_SIZE] =
{
	"cd", "echo", "env", "setenv",
	"unsetenv", "exit"
};

static t_bool		msh_base_cmd_search(char **args)
{
	size_t	i;

	i = -1;
	while (++i < MSH_CMD_SIZE)
		if (!ft_strcmp(*args, g_cmd_string[i]))
		{
			g_cmd_func[i](args + 1);
			return (true);
		}
	return (false);
}

static t_bool		msh_check_path(const char *path, char **args)
{
	char	*full_path;
	int32_t	res;

	if (!(full_path = ft_strnew(ft_strlen(path) + ft_strlen(*args) + 1)))
		msh_fatal_err(MALLOC_ERR);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, (char[2]){ UNIX_PATH_SEPARATOR, 0 });
	ft_strcat(full_path, *args);
	if (!(res = access(full_path, F_OK)) && !(res = msh_is_dir(full_path)))
		msh_exec(full_path, args);
	ft_memdel((void **)&full_path);
	return (res ? false : true);
}

static t_bool		msh_env_path_cmd_search(char **args)
{
	char	*path_value;
	char	**paths;
	size_t	i;

	if ((path_value = msh_getenv_vlu_by_key(PATH_ENV)))
	{
		if (!(paths = ft_strsplit(path_value, PATH_ENV_SEPARATOR)))
			msh_fatal_err(MALLOC_ERR);
		i = -1;
		while (paths[++i])
			if (msh_check_path(paths[i], args))
			{
				ft_arrdel(&paths);
				return (true);
			}
		ft_arrdel(&paths);
	}
	return (false);
}

static t_bool		msh_full_path_cmd_search(const char *full_path, char **args)
{
	if (!ft_strchr(full_path, UNIX_PATH_SEPARATOR))
		return (false);
	if (!msh_check_path_permision(full_path, SHELL_NAME ": "))
	{
		if (msh_is_dir(full_path))
		{
			PRINT_ERR(MSH_IS_A_DIR, full_path);
		}
		else
			msh_exec(full_path, args);
	}
	return (true);
}

void				msh_process_cmd(char **args)
{
	msh_setenv_one_env(PREV_CMD_ENV, *args);
	if (!msh_base_cmd_search(args) &&
		!msh_full_path_cmd_search(*args, args) &&
		!msh_env_path_cmd_search(args))
	{
		PRINT_ERR(MSH_CMD_NOT_FOUND, *args);
	}
}
