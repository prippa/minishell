/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:32 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin_static_arr.h"
#include "environ_manipulation.h"

#define SH_CMD_NOT_FOUND	SHELL_NAME ": %s: command not found"

static t_bool		sh_base_cmd_search(char **args)
{
	size_t	i;

	i = -1;
	while (++i < SH_CMD_SIZE)
		if (!ft_strcmp(*args, g_cmd_string[i]))
		{
			g_cmd_func[i](args + 1);
			return (true);
		}
	return (false);
}

static t_bool		sh_check_path(const char *path, char **args)
{
	char	*full_path;
	int32_t	res;

	GET_MEM(MALLOC_ERR, full_path, ft_strnew,
		ft_strlen(path) + ft_strlen(*args) + 1);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, (char[2]){ UNIX_PATH_SEPARATOR, 0 });
	ft_strcat(full_path, *args);
	if (!(res = access(full_path, F_OK)) &&
		!(res = sh_is_dir(full_path)))
		sh_exec(full_path, args);
	ft_memdel((void **)&full_path);
	return (res ? false : true);
}

static t_bool		sh_env_path_cmd_search(t_list2 *env_start, char **args)
{
	char	*path_value;
	char	**paths;
	size_t	i;

	if ((path_value = env_get_vlu_by_key(env_start, PATH_ENV)))
	{
		GET_MEM(MALLOC_ERR, paths, ft_strsplit, path_value, PATH_ENV_SEPARATOR);
		i = -1;
		while (paths[++i])
			if (sh_check_path(paths[i], args))
			{
				ft_arrdel(&paths);
				return (true);
			}
		ft_arrdel(&paths);
	}
	return (false);
}

static t_bool		sh_full_path_cmd_search(t_list2 *env_start,
						const char *full_path, char **args)
{
	char *value;

	if (!ft_strchr(full_path, UNIX_PATH_SEPARATOR) &&
		(value = env_get_vlu_by_key(env_start, PATH_ENV)) &&
		ft_strcmp(value, EMPTY_STR))
		return (false);
	if (!sh_path_access(full_path, SHELL_NAME ": "))
	{
		if (sh_is_dir(full_path))
		{
			PRINT_ERR(EXIT_FAILURE, SH_IS_A_DIR, full_path);
		}
		else
			sh_exec(full_path, args);
	}
	return (true);
}

void				sh_process_cmd(t_list2 **env_start, t_list2 **env_end,
						char **args)
{
	env_set(env_start, env_end, ENV(PREV_CMD_ENV, *args), true);
	ft_to_str_lower(args);
	if (!sh_base_cmd_search(args) &&
		!sh_full_path_cmd_search(*env_start, *args, args) &&
		!sh_env_path_cmd_search(*env_start, args))
	{
		PRINT_ERR(EXIT_FAILURE, SH_CMD_NOT_FOUND, *args);
	}
}
