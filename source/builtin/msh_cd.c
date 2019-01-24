/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:41 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CD_DASH_F			"-"

#define CD					"cd: "
#define CD_TO_MANY_ARGS		CD "too many arguments\n"
#define CD_NOT_DIR			CD "not a directory: %s\n"
#define CD_PERM_DENIED		CD "%s: Permission denied\n"
#define CD_NONEXIST_PATH	CD "no such file or directory: %s\n"
#define CD_FILENAME_TO_LONG	CD "file name too long: %s\n"

#define CD_NO_ENV			CD "%s not set\n"

#define	CHDIR_FAILED		"chdir failed\n"

static t_bool	msh_cd_path_valid(t_minishel *msh, const char *path)
{
	if (!msh_is_valid_path(path))
		ft_dprintf(STDERR_FILENO, CD_FILENAME_TO_LONG, path);
	else if (access(path, F_OK) == ERR)
		ft_dprintf(STDERR_FILENO, CD_NONEXIST_PATH, path);
	else if (!msh_is_dir(msh, path))
		ft_dprintf(STDERR_FILENO, CD_NOT_DIR, path);
	else if (access(path, X_OK) == ERR)
		ft_dprintf(STDERR_FILENO, CD_PERM_DENIED, path);
	else
		return (true);
	return (false);
}

static void		msh_cd_make_move(t_minishel *msh, const char *path)
{
	msh_set_pwd(msh, OLDPWD_ENV);
	if ((chdir(path)) == ERR)
		msh_error_exit(msh, CHDIR_FAILED);
	msh_set_pwd(msh, PWD_ENV);
}

static t_bool	msh_cd_by_env(t_minishel *msh, const char *env_key)
{
	const char *path;

	if (!(path = msh_env_get_value_by_key(msh->env_start,
		env_key, ft_strlen(env_key))))
	{
		ft_dprintf(STDERR_FILENO, CD_NO_ENV, env_key);
		return (false);
	}
	if (!msh_cd_path_valid(msh, path))
		return (false);
	if (!(path = ft_strdup(path)))
		msh_error_exit(msh, MALLOC_ERR);
	msh_cd_make_move(msh, path);
	ft_strdel((char **)&path);
	return (true);
}

void			msh_cd(t_minishel *msh, char **args)
{
	if (!*args)
		msh->success_exec = msh_cd_by_env(msh, HOME_ENV);
	else if (*(args + 1))
	{
		ft_dprintf(STDERR_FILENO, CD_TO_MANY_ARGS);
		msh->success_exec = false;
	}
	else if (!ft_strcmp(*args, CD_DASH_F))
		msh->success_exec = msh_cd_by_env(msh, OLDPWD_ENV);
	else if ((msh->success_exec = msh_cd_path_valid(msh, *args)))
		msh_cd_make_move(msh, *args);
	if (msh->success_exec)
		msh_update_curent_dir_name(msh);
}
