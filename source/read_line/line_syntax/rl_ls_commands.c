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

int32_t	ls_backslash_check(t_line_syntax *ls)
{
	(void)ls;
	if (!rl()->line[++rl()->i])
	{
		GET_MEM(MALLOC_ERR, rl()->line, ft_strsub_free,
			&rl()->line, 0, rl()->i - 1);
		rl()->new_line_flag = false;
		return (RL_SLASH);
	}
	return (RL_OK);
}

int32_t	ls_dobule_q_check(t_line_syntax *ls)
{
	(void)ls;
	while (true)
	{
		if (!rl()->line[++rl()->i] ||
			(rl()->line[rl()->i] == BACKSLASH_C && !rl()->line[rl()->i + 1]))
		{
			if (rl()->line[rl()->i] == BACKSLASH_C && !rl()->line[rl()->i + 1])
			{
				GET_MEM(MALLOC_ERR, rl()->line, ft_strsub_free,
					&rl()->line, 0, rl()->i);
				rl()->new_line_flag = false;
			}
			return (RL_DQ);
		}
		if (rl()->line[rl()->i] == BACKSLASH_C)
			++rl()->i;
		else if (rl()->line[rl()->i] == DOUBLE_QUOTES_C)
			return (RL_OK);
	}
}

int32_t	ls_single_q_check(t_line_syntax *ls)
{
	(void)ls;
	while (true)
	{
		if (!rl()->line[++rl()->i])
			return (RL_Q);
		if (rl()->line[rl()->i] == SINGLE_QUOTES_C)
			return (RL_OK);
	}
}

int32_t	ls_semi_check(t_line_syntax *ls)
{
	if (!ls->semi_flag)
	{
		if (rl()->line[rl()->i + 1] == SEMICOLON_C || (rl()->i &&
			rl()->line[rl()->i - 1] == SEMICOLON_C))
			return (RL_SEMIX2);
		else
			return (RL_SEMIX1);
	}
	ls->semi_flag = false;
	return (RL_OK);
}
