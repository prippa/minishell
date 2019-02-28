/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:41 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"

#define CD_DASH_F			"-"
#define CD					CD_CMD ": "
#define CD_TO_MANY_ARGS		CD TO_MANY_ARGS
#define CD_NOT_DIR			CD "'%s': Not a directory"
#define CD_PERM_DENIED		CD PERM_DENIED
#define CD_FILENAME_TO_LONG	CD "'%s': File name too long"
#define CD_NO_ENV			CD "%s not set"

static t_bool	sh_cd_path_valid(const char *path)
{
	if (sh_is_valid_path(path))
	{
		PRINT_ERR(EXIT_FAILURE, CD_FILENAME_TO_LONG, path);
	}
	else if (sh_path_access(path, CD))
		return (g_ok);
	else if (!sh_is_dir(path))
	{
		PRINT_ERR(EXIT_FAILURE, CD_NOT_DIR, path);
	}
	else if (access(path, X_OK) == ERR)
	{
		PRINT_ERR(EXIT_FAILURE, CD_PERM_DENIED, path);
	}
	return (g_ok);
}

static void		sh_cd_make_move(const char *path)
{
	char *pwd;

	if ((pwd = sh_getenv_vlu_by_key(PWD_ENV, ft_strlen(PWD_ENV))))
		sh_setenv_one_env(OLDPWD_ENV, pwd);
	else if (sh_getenv_vlu_by_key(OLDPWD_ENV, ft_strlen(OLDPWD_ENV)))
		sh_unsetenv_one_env(OLDPWD_ENV);
	if ((chdir(path)) == ERR)
		sh_fatal_err(CHDIR_FAILED);
	if (!(pwd = getcwd(NULL, 0)))
		sh_fatal_err(GETCWD_FAILED);
	sh_setenv_one_env(PWD_ENV, pwd);
	ft_memdel((void **)&pwd);
}

static void		sh_cd_by_env(const char *env_key)
{
	char *path;

	if (!(path = sh_getenv_vlu_by_key(env_key, ft_strlen(env_key))))
	{
		PRINT_ERR(EXIT_FAILURE, CD_NO_ENV, env_key);
		return ;
	}
	if (!sh_cd_path_valid(path))
		return ;
	if (!(path = ft_strdup(path)))
		sh_fatal_err(MALLOC_ERR);
	sh_cd_make_move(path);
	ft_memdel((void **)&path);
}

void			sh_cd(char **args)
{
	if (!*args)
		sh_cd_by_env(HOME_ENV);
	else if (*(args + 1))
	{
		PRINT_ERR(EXIT_FAILURE, CD_TO_MANY_ARGS, NULL);
	}
	else if (!ft_strcmp(*args, CD_DASH_F))
		sh_cd_by_env(OLDPWD_ENV);
	else if (sh_cd_path_valid(*args))
		sh_cd_make_move(*args);
	if (g_ok)
		sh_update_curent_dir_name();
}
