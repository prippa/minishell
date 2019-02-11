/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:59:19 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:59:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"

#define LS_CMD_SIZE	4

typedef t_bool		(*t_func_cmd)(t_line_syntax *ls);
static const		t_func_cmd	g_ls_cmd_f[LS_CMD_SIZE] =
{
	ls_single_q_check, ls_dobule_q_check, ls_backslash_check, ls_semi_check
};

static const char	g_ls_cmd_c[LS_CMD_SIZE] =
{
	SINGLE_QUOTES_C, DOUBLE_QUOTES_C, BACKSLASH_C, SEMICOLON_C
};

static void			line_syntax_loop(t_line_syntax *ls)
{
	uint8_t	i;

	g_msh.i = -1;
	while (g_msh.line[++g_msh.i])
	{
		i = -1;
		while (++i < LS_CMD_SIZE)
			if (g_msh.line[g_msh.i] == g_ls_cmd_c[i])
			{
				if (!g_ls_cmd_f[i](ls))
					return ;
				break ;
			}
		if (g_msh.i != SIZE_MAX && !ft_isspace(g_msh.line[g_msh.i]) &&
			g_msh.line[g_msh.i] != SEMICOLON_C)
			ls->semi_flag = true;
	}
}

void				line_syntax(void)
{
	t_line_syntax ls;

	ft_bzero(&ls, sizeof(t_line_syntax));
	line_syntax_loop(&ls);
}
