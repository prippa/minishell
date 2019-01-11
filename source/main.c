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

static void	msh_update_prompt(t_msh *msh)
{
	ft_strcpy(msh->prompt, (msh->execute_flag ? BOLD_GREEN : BOLD_RED));
	ft_strcat(msh->prompt, MSH_P_ICON);
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_CYAN);
	ft_strcat(msh->prompt, " <[");
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_MAGENTA);
	ft_strcat(msh->prompt, "dir");
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_CYAN);
	ft_strcat(msh->prompt, "]> ");
	ft_strcat(msh->prompt, COLOR_RESET);
}

static void	msh_loop(t_msh *msh)
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
			msh->execute_flag = true;
		}
		ft_strdel(&msh->line);
	}
}

static void	msh_init(t_msh *msh, char **environ)
{
	ft_bzero(msh, sizeof(t_msh));
	// msh_setenv(msh, environ);
	msh->execute_flag = true;
}

int			main(int argc, char **argv, char **environ)
{
	t_msh	msh;

	(void)argc;
	(void)argv;
	msh_init(&msh, environ);
	msh_loop(&msh);
	return (0);
}
