/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:57:49 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:57:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "messages.h"
#include "syntax_characters.h"
#include "builtin.h"

#define LS_ERR				SHELL_NAME ": syntax error : "
#define WTF_SEMICOLON_X1	LS_ERR "near unexpected token `;'"
#define WTF_SEMICOLON_X2	LS_ERR "near unexpected token `;;'"

#define QUOT_PROMPT		"quote> "
#define DQUOT_PROMPT	"dquote> "
#define SLASH_PROMPT	"> "

t_bool		ls_backslash_check(t_read_line *rl, t_line_syntax *ls)
{
	(void)ls;
	if (!rl->line[++rl->i])
	{
		if (!ft_strsub_free(&rl->line, 0, rl->i - 1))
			sh_fatal_err(MALLOC_ERR);
		write(STDOUT_FILENO, SLASH_PROMPT, ft_strlen(SLASH_PROMPT));
		rl->new_line_flag = false;
		return (false);
	}
	return (true);
}

t_bool		ls_dobule_q_check(t_read_line *rl, t_line_syntax *ls)
{
	(void)ls;
	while (true)
	{
		if (!rl->line[++rl->i] ||
			(rl->line[rl->i] == BACKSLASH_C && !rl->line[rl->i + 1]))
		{
			if (rl->line[rl->i] == BACKSLASH_C && !rl->line[rl->i + 1])
			{
				if (!ft_strsub_free(&rl->line, 0, rl->i))
					sh_fatal_err(MALLOC_ERR);
				rl->new_line_flag = false;
			}
			write(STDOUT_FILENO, DQUOT_PROMPT, ft_strlen(DQUOT_PROMPT));
			return (false);
		}
		if (rl->line[rl->i] == BACKSLASH_C)
			ls_backslash_check(rl, ls);
		else if (rl->line[rl->i] == DOUBLE_QUOTES_C)
			return (true);
	}
}

t_bool		ls_single_q_check(t_read_line *rl, t_line_syntax *ls)
{
	(void)ls;
	while (true)
	{
		if (!rl->line[++rl->i])
		{
			write(STDOUT_FILENO, QUOT_PROMPT, ft_strlen(QUOT_PROMPT));
			return (false);
		}
		if (rl->line[rl->i] == SINGLE_QUOTES_C)
			return (true);
	}
}

t_bool		ls_semi_check(t_read_line *rl, t_line_syntax *ls)
{
	if (!ls->semi_flag)
	{
		if (rl->line[rl->i + 1] == SEMICOLON_C || (rl->i &&
			rl->line[rl->i - 1] == SEMICOLON_C))
		{
			PRINT_ERR(EXIT_FAILURE, WTF_SEMICOLON_X2, NULL);
		}
		else
		{
			PRINT_ERR(EXIT_FAILURE, WTF_SEMICOLON_X1, NULL);
		}
		return (false);
	}
	ls->semi_flag = false;
	return (true);
}
