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
#define CD_TO_MANY_ARGS		CD "Too many arguments\n"
#define CD_NOT_DIR			CD "'%s': Not a directory\n"
#define CD_PERM_DENIED		CD "'%s': Permission denied\n"
#define CD_NONEXIST_PATH	CD "'%s': No such file or directory\n"
#define CD_FILENAME_TO_LONG	CD "'%s': File name too long\n"

#define CD_NO_ENV			CD "%s not set\n"

#define	CHDIR_FAILED		"chdir failed\n"
#define GETCWD_FAILED		"getcwd failed\n"

static t_bool	msh_cd_path_valid(const char *path)
{
	if (!msh_is_valid_path(path))
	{
		PRINT_ERR(CD_FILENAME_TO_LONG, path);
	}
	else if (access(path, F_OK) == ERR)
	{
		PRINT_ERR(CD_NONEXIST_PATH, path);
	}
	else if (!msh_is_dir(path))
	{
		PRINT_ERR(CD_NOT_DIR, path);
	}
	else if (access(path, X_OK) == ERR)
	{
		PRINT_ERR(CD_PERM_DENIED, path);
	}
	return (g_ok);
}

static void		msh_set_pwd(const char *pwd_name)
{
	char	*pwd;
	char	*env;

	if (!(pwd = getcwd(NULL, 0)))
		msh_fatal_err(GETCWD_FAILED);
	if (!(env = ft_strnew(ft_strlen(pwd_name) + ft_strlen(pwd) + 1)))
		msh_fatal_err(MALLOC_ERR);
	ft_strcpy(env, pwd_name);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, pwd);
	msh_setenv_one_env(env);
	ft_strdel(&pwd);
	ft_strdel(&env);
}

static void		msh_cd_make_move(const char *path)
{
	msh_set_pwd(OLDPWD_ENV);
	if ((chdir(path)) == ERR)
		msh_fatal_err(CHDIR_FAILED);
	msh_set_pwd(PWD_ENV);
}

static void		msh_cd_by_env(const char *env_key)
{
	const char *path;

	if (!(path = msh_getenv_value_by_key(g_msh.env_start,
		env_key, ft_strlen(env_key))))
	{
		PRINT_ERR(CD_NO_ENV, env_key);
		return ;
	}
	if (!msh_cd_path_valid(path))
		return ;
	if (!(path = ft_strdup(path)))
		msh_fatal_err(MALLOC_ERR);
	msh_cd_make_move(path);
	ft_strdel((char **)&path);
}

void			msh_cd(char **args)
{
	if (!*args)
		msh_cd_by_env(HOME_ENV);
	else if (*(args + 1))
	{
		PRINT_ERR(CD_TO_MANY_ARGS, NULL);
	}
	else if (!ft_strcmp(*args, CD_DASH_F))
		msh_cd_by_env(OLDPWD_ENV);
	else if ((msh_cd_path_valid(*args)))
		msh_cd_make_move(*args);
	if (g_ok)
		msh_update_curent_dir_name();
}
