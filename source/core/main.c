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
#include "get_next_line.h"
#include "builtin.h"

#define MSH_OK_ICON		BOLD_GREEN "✓"
#define MSH_ERROR_ICON	BOLD_RED "✕"

void		msh_update_prompt(void)
{
	ft_strcpy(g_msh.prompt, (g_ok ? MSH_OK_ICON : MSH_ERROR_ICON));
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_MAGENTA);
	ft_strcat(g_msh.prompt, " (");
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_YELLOW);
	ft_strcat(g_msh.prompt, g_msh.curent_path);
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_MAGENTA);
	ft_strcat(g_msh.prompt, ") ");
	ft_strcat(g_msh.prompt, COLOR_RESET);
}

static void	msh_loop(void)
{
	while ((g_msh.line = read_line(g_msh.prompt)))
	{
		if (!ft_is_str_space(g_msh.line))
		{
			if (g_ok)
				line_parser();
			if (g_ok)
				g_exec_code = EXIT_SUCCESS;
			msh_update_prompt();
			g_ok = true;
		}
		ft_memdel((void **)&g_msh.line);
	}
}

int			main(void)
{
	msh_init();
	msh_loop();
	msh_exit(NULL);
}
