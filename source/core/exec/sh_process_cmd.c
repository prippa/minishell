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

#define SH_CMD_NOT_FOUND	"%s: command not found"

static t_bool		sh_base_cmd_search(t_build *b)
{
	size_t	i;

	i = -1;
	while (++i < SH_CMD_SIZE)
		if (!ft_strcmp(*b->args, g_cmd_string[i]))
		{
			++b->args;
			g_cmd_func[i](b);
			return (true);
		}
	return (false);
}

static t_bool		sh_check_path(const char *path, t_build *b)
{
	char	*full_path;
	int32_t	res;

	GET_MEM(MALLOC_ERR, full_path, ft_strnew,
		ft_strlen(path) + ft_strlen(*b->args) + 1);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, (char[2]){ UNIX_PATH_SEPARATOR, 0 });
	ft_strcat(full_path, *b->args);
	if (!(res = access(full_path, F_OK)) &&
		!(res = sh_is_dir(full_path)))
		sh_exec(full_path, b);
	ft_memdel((void **)&full_path);
	return (res ? false : true);
}

static t_bool		sh_env_path_cmd_search(t_build *b)
{
	char	*path_value;
	char	**paths;
	size_t	i;

	if ((path_value = env_get_vlu_by_key(sh()->env_start, PATH_ENV)))
	{
		GET_MEM(MALLOC_ERR, paths, ft_strsplit, path_value, PATH_ENV_SEPARATOR);
		i = -1;
		while (paths[++i])
			if (sh_check_path(paths[i], b))
			{
				ft_arrdel(&paths);
				return (true);
			}
		ft_arrdel(&paths);
	}
	return (false);
}

static t_bool		sh_full_path_cmd_search(t_build *b, const char *cmd_prefix)
{
	char *value;

	if (!ft_strchr(*b->args, UNIX_PATH_SEPARATOR) &&
		(value = env_get_vlu_by_key(sh()->env_start, PATH_ENV)) &&
		ft_strcmp(value, EMPTY_STR))
		return (false);
	if (!sh_path_access(*b->args, cmd_prefix))
	{
		if (sh_is_dir(*b->args))
		{
			PRINT_ERR(EXIT_FAILURE, SH_IS_A_DIR, *b->args);
		}
		else
			sh_exec(*b->args, b);
	}
	return (true);
}

void				sh_process_cmd(t_build *b, const char *cmd_prefix)
{
	ft_to_str_lower(b->args);
	if (!sh_base_cmd_search(b) &&
		!sh_full_path_cmd_search(b, cmd_prefix) &&
		!sh_env_path_cmd_search(b))
	{
		ft_putstr_fd(cmd_prefix, STDERR_FILENO);
		PRINT_ERR(EXIT_FAILURE, SH_CMD_NOT_FOUND, *b->args);
	}
}
