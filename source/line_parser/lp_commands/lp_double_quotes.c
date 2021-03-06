/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_double_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:57:02 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:57:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"

static t_bool		lp_dqb_adaptation(char c)
{
	if (c == DOLLAR_C ||
		c == BACKSLASH_C ||
		c == DOUBLE_QUOTES_C)
		return (true);
	return (false);
}

static void			lp_double_quotes_backslash(t_line_parser *lp)
{
	if (lp_dqb_adaptation(sh()->line[sh()->i + 1]))
		lp_backslash(lp);
	else
	{
		lp_write_to_arg_buf_str(lp, &sh()->line[sh()->i], 2);
		++sh()->i;
	}
}

#define LP_DOUBLE_QUOTES_SIZE	2

static const		t_func_cmd	g_double_q_f[LP_DOUBLE_QUOTES_SIZE] =
{
	lp_dollar, lp_double_quotes_backslash
};

static const char	g_double_q_c[LP_DOUBLE_QUOTES_SIZE] =
{
	DOLLAR_C, BACKSLASH_C
};

void				lp_double_quotes(t_line_parser *lp)
{
	uint8_t	i;

	while (sh()->line[++sh()->i] != DOUBLE_QUOTES_C)
	{
		i = -1;
		while (++i < LP_DOUBLE_QUOTES_SIZE)
			if (sh()->line[sh()->i] == g_double_q_c[i])
			{
				g_double_q_f[i](lp);
				break ;
			}
		if (i == LP_DOUBLE_QUOTES_SIZE)
			lp_write_to_arg_buf_char(lp, sh()->line[sh()->i]);
	}
}
