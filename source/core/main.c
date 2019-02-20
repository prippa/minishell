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

#define MSH_OK_ICON		BOLD_GREEN "✓"
#define MSH_ERROR_ICON	BOLD_RED "✕"

void		msh_update_prompt(void)
{
	ft_strcpy(g_msh.prompt, (g_ok ? MSH_OK_ICON : MSH_ERROR_ICON));
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_MAGENTA);
	ft_strcat(g_msh.prompt, " (");
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_CYAN);
	ft_strcat(g_msh.prompt, g_msh.curent_path);
	ft_strcat(g_msh.prompt, COLOR_RESET);
	ft_strcat(g_msh.prompt, BOLD_MAGENTA);
	ft_strcat(g_msh.prompt, ") ");
	ft_strcat(g_msh.prompt, COLOR_RESET);
}

static void	msh_loop(void)
{
	ft_putstr(g_msh.prompt);
	while ((get_next_line(STDIN_FILENO, &g_msh.line)) > 0)
	{
		if (!ft_is_str_space(g_msh.line))
		{
			line_syntax();
			if (g_ok)
				line_parser();
			msh_update_prompt();
			g_ok = true;
		}
		ft_memdel((void **)&g_msh.line);
		ft_putstr(g_msh.prompt);
	}
}

int			main(void)
{
	msh_init();
	msh_loop();
	return (EXIT_SUCCESS);
}
