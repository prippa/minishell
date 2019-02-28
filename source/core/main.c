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

#include "shell.h"
#include "get_next_line.h"
#include "builtin.h"

#define SH_OK_ICON		BOLD_GREEN "✓"
#define SH_ERROR_ICON	BOLD_RED "✕"

void		sh_update_prompt(void)
{
	ft_strcpy(g_sh.prompt, (g_ok ? SH_OK_ICON : SH_ERROR_ICON));
	ft_strcat(g_sh.prompt, COLOR_RESET);
	ft_strcat(g_sh.prompt, BOLD_MAGENTA);
	ft_strcat(g_sh.prompt, " (");
	ft_strcat(g_sh.prompt, COLOR_RESET);
	ft_strcat(g_sh.prompt, BOLD_YELLOW);
	ft_strcat(g_sh.prompt, g_sh.curent_path);
	ft_strcat(g_sh.prompt, COLOR_RESET);
	ft_strcat(g_sh.prompt, BOLD_MAGENTA);
	ft_strcat(g_sh.prompt, ") ");
	ft_strcat(g_sh.prompt, COLOR_RESET);
}

static void	sh_loop(void)
{
	while ((g_sh.line = read_line(g_sh.prompt)))
	{
		if (!ft_is_str_space(g_sh.line))
		{
			if (g_ok)
				line_parser();
			if (g_ok)
				g_exec_code = EXIT_SUCCESS;
			sh_update_prompt();
			g_ok = true;
		}
		ft_memdel((void **)&g_sh.line);
	}
}

int			main(void)
{
	sh_init();
	sh_loop();
	sh_exit(NULL);
}
