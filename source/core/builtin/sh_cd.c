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
#include "environ_manipulation.h"

#define CD_DASH_F			"-"
#define CD					CD_CMD ": "
#define CD_TO_MANY_ARGS		CD TO_MANY_ARGS
#define CD_NOT_DIR			CD "'%s': Not a directory"
#define CD_PERM_DENIED		CD PERM_DENIED
#define CD_FILENAME_TO_LONG	CD "'%s': File name too long"
#define CD_NO_ENV			CD "%s not set"
#define CD_L_F				"-L"
#define CD_P_F				"-P"

static t_bool	sh_cd_path_valid(const char *path)
{
	if (sh_is_valid_path(path))
	{
		PRINT_ERR(EXIT_FAILURE, CD_FILENAME_TO_LONG, path);
	}
	else if (sh_path_access(path, CD))
		return (sh()->ok);
	else if (!sh_is_dir(path))
	{
		PRINT_ERR(EXIT_FAILURE, CD_NOT_DIR, path);
	}
	else if (access(path, X_OK) == ERR)
	{
		PRINT_ERR(EXIT_FAILURE, CD_PERM_DENIED, path);
	}
	return (sh()->ok);
}

static void		sh_cd_make_move(t_list2 *env_start, t_list2 *env_end,
					const char *path, t_bool slf)
{
	char *pwd;(void)slf;

	if ((pwd = env_get_vlu_by_key(env_start, PWD_ENV)))
		env_set(&env_start, &env_end, ENV(OLDPWD_ENV, pwd), true);
	else if (env_get_vlu_by_key(env_start, OLDPWD_ENV))
		env_unset(&env_start, &env_end, OLDPWD_ENV);
	if ((chdir(path)) == ERR)
		sh_fatal_err(CHDIR_FAILED);
	GET_MEM(GETCWD_FAILED, pwd, getcwd, NULL, 0);
	env_set(&env_start, &env_end, ENV(PWD_ENV, pwd), true);
	ft_memdel((void **)&pwd);
}

static t_bool	sh_cd_by_env(t_list2 *env_start, t_list2 *env_end,
					const char *env_key, t_bool slf)
{
	char *path;

	if (!(path = env_get_vlu_by_key(env_start, env_key)))
	{
		PRINT_ERR(EXIT_FAILURE, CD_NO_ENV, env_key);
		return (false);
	}
	if (!sh_cd_path_valid(path))
		return (false);
	GET_MEM(MALLOC_ERR, path, ft_strdup, path);
	sh_cd_make_move(env_start, env_end, path, slf);
	ft_memdel((void **)&path);
	return (true);
}

static t_bool	sh_cd_check_flags(char ***args)
{
	t_bool f;

	f = false;
	while (**args)
	{
		if (!ft_strcmp(CD_L_F, **args))
			f = false;
		else if (!ft_strcmp(CD_P_F, **args))
			f = true;
		else
			break ;
		++(*args);
	}
	return (f);
}

void			sh_cd(t_build *b)
{
	t_bool	symb_link_flag;

	symb_link_flag = sh_cd_check_flags(&b->args);
	if (!*b->args)
		sh_cd_by_env(*b->env_start, *b->env_end, HOME_ENV, symb_link_flag);
	else if (*(b->args + 1))
	{
		PRINT_ERR(EXIT_FAILURE, CD_TO_MANY_ARGS, NULL);
	}
	else if (!ft_strcmp(*b->args, CD_DASH_F) &&
		sh_cd_by_env(*b->env_start, *b->env_end, OLDPWD_ENV, symb_link_flag))
		ft_putendl(env_get_vlu_by_key(*b->env_start, PWD_ENV));
	else if (sh_cd_path_valid(*b->args))
		sh_cd_make_move(*b->env_start, *b->env_end, *b->args, symb_link_flag);
	if (sh()->ok)
		sh_update_curent_dir_name();
}
