/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:59:48 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:59:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "syntax_characters.h"

#define LS_ERR	"line syntax : ERROR : "
#define WTF_EOF	"\n" LS_ERR "unexpected EOF while looking for matching `%c'"
#define WTF_SEMICOLON_X1	LS_ERR "near unexpected token `;'"
#define WTF_SEMICOLON_X2	LS_ERR "near unexpected token `;;'"

t_bool		ls_backslash_check(t_line_syntax *ls)
{
	(void)ls;
	if (!g_msh.line[++g_msh.i])
	{
		g_msh.line[--g_msh.i] = 0;
		if (!ft_strdup_free(&g_msh.line, g_msh.line))
			msh_fatal_err(MALLOC_ERR);
		if (!(ls_read_new_line(false)))
			msh_exit(NULL);
		--g_msh.i;
	}
	return (true);
}

t_bool		ls_dobule_q_check(t_line_syntax *ls)
{
	while (true)
	{
		if (!g_msh.line[++g_msh.i] && !ls_read_new_line(true))
		{
			PRINT_ERR(WTF_EOF, DOUBLE_QUOTES_C);
			return (false);
		}
		if (g_msh.line[g_msh.i] == BACKSLASH_C)
			ls_backslash_check(ls);
		else if (g_msh.line[g_msh.i] == DOUBLE_QUOTES_C)
			return (true);
	}
}

t_bool		ls_single_q_check(t_line_syntax *ls)
{
	(void)ls;
	while (true)
	{
		if (!g_msh.line[++g_msh.i] && !ls_read_new_line(true))
		{
			PRINT_ERR(WTF_EOF, SINGLE_QUOTES_C);
			return (false);
		}
		if (g_msh.line[g_msh.i] == SINGLE_QUOTES_C)
			return (true);
	}
}

t_bool		ls_semi_check(t_line_syntax *ls)
{
	if (!ls->semi_flag)
	{
		if (g_msh.line[g_msh.i + 1] == SEMICOLON_C || (g_msh.i &&
			g_msh.line[g_msh.i - 1] == SEMICOLON_C))
		{
			PRINT_ERR(WTF_SEMICOLON_X2, NULL);
		}
		else
		{
			PRINT_ERR(WTF_SEMICOLON_X1, NULL);
		}
		return (false);
	}
	ls->semi_flag = false;
	return (true);
}
