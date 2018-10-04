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

static void	msh_construct_prompt(t_msh *msh)
{
	ft_strcpy(msh->prompt, BOLD_GREEN);
	ft_strcat(msh->prompt, MSH_P_ICON);
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_CYAN);
	ft_strcat(msh->prompt, " <[");
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_MAGENTA);
	ft_strcat(msh->prompt, msh->curent_dir_path);
	ft_strcat(msh->prompt, COLOR_RESET);
	ft_strcat(msh->prompt, BOLD_CYAN);
	ft_strcat(msh->prompt, "]> ");
	ft_strcat(msh->prompt, COLOR_RESET);
}

static void	msh_loop(t_msh *msh)
{
	msh_update_curent_dir_name(msh);
	msh_construct_prompt(msh);
	while ((msh->line = readline(msh->prompt)))
	{
		if (*msh->line)
		{
			msh_parse_line(msh);
			add_history(msh->line);
		}
		ft_strdel(&msh->line);
	}
}

static void	msh_init(t_msh *msh, char **environ)
{
	t_list2	*new_obj;
	t_env	e;
	size_t	separate_index;

	ft_bzero(msh, sizeof(t_msh));
	while (*environ)
	{
		separate_index = ft_strchr(*environ, '=') - *environ;
		(*environ)[separate_index] = 0;
		if (!(e.name = ft_strdup(*environ)))
			msh_error_exit(msh, MALLOC_ERR);
		if (!(e.arg = ft_strdup(&(*environ)[separate_index + 1])))
			msh_error_exit(msh, MALLOC_ERR);
		if (!(new_obj = ft_lst2new(&e, sizeof(t_env))))
			msh_error_exit(msh, MALLOC_ERR);
		ft_lst2_push_back(&msh->env_start, &msh->env_end, new_obj);
		++environ;
	}
}

int			main(int argc, char **argv, char **environ)
{
	t_msh	msh;

	(void)argc;
	(void)argv;
	msh_init(&msh, environ);
	msh_loop(&msh);
	msh_free(&msh);
	return (0);
}
