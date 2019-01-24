/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 18:10:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include "syntax_characters.h"

#define STAT_FAILED		"stat failed\n"
#define GETCWD_FAILED	"getcwd failed\n"

t_bool		msh_is_dir(t_minishel *msh, const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		msh_error_exit(msh, STAT_FAILED);
	return (S_ISDIR(sb.st_mode));
}

t_bool		msh_is_valid_path(const char *path)
{
	uint16_t	i;

	i = 0;
	while (*path)
	{
		if (*path == UNIX_PATH_SEPARATOR)
			i = 0;
		else if (++i > FILE_NAME_MAX)
			return (false);
		++path;
	}
	return (true);
}

void		msh_set_pwd(t_minishel *msh, const char *pwd_name)
{
	char	*pwd;
	char	*env;

	if (!(pwd = getcwd(NULL, 0)))
		msh_error_exit(msh, GETCWD_FAILED);
	if (!(env = ft_strnew(ft_strlen(pwd_name) + ft_strlen(pwd) + 1)))
		msh_error_exit(msh, MALLOC_ERR);
	ft_strcpy(env, pwd_name);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, pwd);
	msh_setenv_one_env(msh, env);
	ft_strdel(&pwd);
	ft_strdel(&env);
}

void		msh_update_curent_dir_name(t_minishel *msh)
{
	const char	*home;
	char		*file;
	char		*pwd;

	if (!(pwd = getcwd(NULL, 0)))
		msh_error_exit(msh, GETCWD_FAILED);
	if ((home = msh_env_get_value_by_key(msh->env_start,
		HOME_ENV, ft_strlen(HOME_ENV))) && !ft_strcmp(home, pwd))
		ft_strcpy(msh->curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(msh->curent_path, file);
	}
	else
		ft_strcpy(msh->curent_path, pwd);
	ft_strdel(&pwd);
}

void		msh_print_error(t_minishel *msh, const char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	msh->success_exec = false;
}
