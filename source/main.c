/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:11 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

#define MSH_OK_ICON		"✓"
#define MSH_ERROR_ICON	"✕"

void		msh_update_curent_dir_name(t_minishel *msh)
{
	const char *path;

	if ((path = msh_env_get_arg_by_name(msh->env_start, "PWD", ft_strlen("PWD"))))
		ft_strcpy(msh->curent_path, path);
}

static void	msh_update_prompt(t_minishel *msh)
{
	ft_strcpy(msh->prompt, (msh->success_exec ? MSH_OK_ICON : MSH_ERROR_ICON));
	ft_strcat(msh->prompt, " (");
	ft_strcat(msh->prompt, msh->curent_path);
	ft_strcat(msh->prompt, ") ");
}

static void	msh_loop(t_minishel *msh)
{
	msh_update_curent_dir_name(msh);
	msh_update_prompt(msh);
	while ((msh->line = readline(msh->prompt)))
	{
		if (*msh->line)
		{
			msh_execute_command(msh);
			msh_update_prompt(msh);
			add_history(msh->line);
			msh->success_exec = true;
		}
		ft_strdel(&msh->line);
	}
}

static void	msh_init(t_minishel *msh)
{
	extern char	**environ;

	ft_bzero(msh, sizeof(t_minishel));
	msh_setenv(msh, environ);
	msh->success_exec = true;
}

int			main(void)
{
	t_minishel	msh;

	msh_init(&msh);
	msh_loop(&msh);
	msh_free(&msh);
	system("leaks -q minishell");
	return (EXIT_SUCCESS);
}
