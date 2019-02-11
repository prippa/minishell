/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:41:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:41:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

#define LP_BASE_SIZE	8

static const char	g_base_c[LP_BASE_SIZE] =
{
	SPACE_C, TAB_C, DOLLAR_C, SEMICOLON_C,
	SINGLE_QUOTES_C, DOUBLE_QUOTES_C, BACKSLASH_C, TILDE_C
};

static const		t_func_cmd	g_base_f[LP_BASE_SIZE] =
{
	lp_space, lp_space, lp_dollar, lp_semicolon,
	lp_single_quotes, lp_double_quotes, lp_backslash, lp_tilde
};

static void			lp_loop(t_line_parser *lp)
{
	uint8_t i;

	g_msh.i = -1;
	while (g_msh.line[++g_msh.i])
	{
		i = -1;
		while (++i < LP_BASE_SIZE)
			if (g_msh.line[g_msh.i] == g_base_c[i])
			{
				g_base_f[i](lp);
				break ;
			}
		if (i == LP_BASE_SIZE)
			lp_write_to_arg_buf_char(lp, g_msh.line[g_msh.i]);
	}
	lp_push_command(lp);
}

void				line_parser(void)
{
	t_line_parser lp;

	ft_bzero(&lp, sizeof(t_line_parser));
	lp_loop(&lp);
}
