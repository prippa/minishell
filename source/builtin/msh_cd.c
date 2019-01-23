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
#include "ft_printf.h"

typedef struct	s_cd_flags
{
	t_bool		dash;
}				t_cd_flags;

#define CD_DASH_F			"-"

#define CD					"cd: "
#define CD_TO_MANY_ARGS		CD "too many arguments\n"
#define CD_NOT_DIR			CD "not a directory: %s\n"
#define CD_PERM_DENIED		CD "%s: Permission denied\n"
#define CD_NONEXIST_PATH	CD "no such file or directory: %s\n"
#define CD_FILENAME_TO_LONG	CD "file name too long: %s\n"

static t_bool	msh_cd_valid(t_minishel *msh, char **args)
{
	if (!*args)
		return (true);
	if (ft_arrlen(args) > 1)
		ft_dprintf(STDERR_FILENO, CD_TO_MANY_ARGS);
	else if (!msh_is_valid_path(*args))
		ft_dprintf(STDERR_FILENO, CD_FILENAME_TO_LONG, *args);
	else if (access(*args, F_OK) == ERR)
		ft_dprintf(STDERR_FILENO, CD_NONEXIST_PATH, *args);
	else if (!msh_is_dir(msh, *args))
		ft_dprintf(STDERR_FILENO, CD_NOT_DIR, *args);
	else if (access(*args, X_OK) == ERR)
		ft_dprintf(STDERR_FILENO, CD_PERM_DENIED, *args);
	else
		return (true);
	return (false);
}

static void	msh_cd_flags(t_cd_flags *f, char ***args)
{
	while (**args)
	{
		if (!ft_strcmp(**args, CD_DASH_F))
			f->dash = true;
		else
			break ;
		++(*args);
	}
}

void			msh_cd(t_minishel *msh, char **args)
{
	t_cd_flags f;

	ft_bzero(&f, sizeof(t_cd_flags));
	msh_cd_flags(&f, &args);
	if (!(msh->success_exec = msh_cd_valid(msh, args)))
		return ;
	(void)args;
	char *pwd = getcwd(NULL, 0);
	ft_printf("%s\n", msh->curent_path);
	ft_putendl("cd");
	free(pwd);
}
