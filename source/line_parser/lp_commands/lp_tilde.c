/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:56:30 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:56:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"
#include "messages.h"

static t_bool	lp_tilde_valid_prev(const char *line, size_t i)
{
	if (!(i + 1) ||
		line[i] == SPACE_C ||
		line[i] == SEMICOLON_C)
		return (true);
	return (false);
}

static t_bool	lp_tilde_valid_next(const char *line, size_t i)
{
	if (!line[i] ||
		line[i] == SPACE_C ||
		line[i] == UNIX_PATH_SEPARATOR ||
		line[i] == SEMICOLON_C)
		return (true);
	return (false);
}

void			lp_tilde(t_line_parser *lp)
{
	char	*home;

	if (lp_tilde_valid_prev(g_msh.line, g_msh.i - 1) &&
		lp_tilde_valid_next(g_msh.line, g_msh.i + 1))
	{
		if ((home = msh_getenv_vlu_by_key(HOME_ENV)))
			lp_write_to_arg_buf_str(lp, home, ft_strlen(home));
	}
	else
		lp_write_to_arg_buf_char(lp, g_msh.line[g_msh.i]);
}
