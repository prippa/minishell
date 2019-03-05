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
	ft_strcpy(sh()->prompt, (sh()->ok ? SH_OK_ICON : SH_ERROR_ICON));
	ft_strcat(sh()->prompt, COLOR_RESET);
	ft_strcat(sh()->prompt, BOLD_MAGENTA);
	ft_strcat(sh()->prompt, " (");
	ft_strcat(sh()->prompt, COLOR_RESET);
	ft_strcat(sh()->prompt, BOLD_YELLOW);
	ft_strcat(sh()->prompt, sh()->curent_path);
	ft_strcat(sh()->prompt, COLOR_RESET);
	ft_strcat(sh()->prompt, BOLD_MAGENTA);
	ft_strcat(sh()->prompt, ") ");
	ft_strcat(sh()->prompt, COLOR_RESET);
}

static void	sh_loop(void)
{
	while ((sh()->line = read_line()))
	{
		if (!ft_is_str_space(sh()->line))
		{
			line_parser();
			if (sh()->ok)
				sh()->exec_code = EXIT_SUCCESS;
			sh_update_prompt();
			sh()->ok = true;
		}
		ft_memdel((void **)&sh()->line);
	}
}

int			main(void)
{
	sh_init();
	sh_loop();
	sh_exit(NULL);
}
