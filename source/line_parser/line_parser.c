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
	SPACE_C, TAB_C, DOLLAR_C, SEMICOLON_C, SINGLE_QUOTES_C, DOUBLE_QUOTES_C,
	BACKSLASH_C, TILDE_C
};

static const		t_func_cmd	g_base_f[LP_BASE_SIZE] =
{
	lp_space, lp_space, lp_dollar, lp_semicolon, lp_single_quotes, lp_double_quotes,
	lp_backslash, lp_tilde
};

static t_bool		lp_loop(t_minishel *msh, t_line_parser *lp)
{
	uint8_t i;

	msh->i = -1;
	while (msh->line[++msh->i])
	{
		i = -1;
		while (++i < LP_BASE_SIZE)
			if (msh->line[msh->i] == g_base_c[i])
			{
				if (!g_base_f[i](msh, lp))
					return (false);
				break ;
			}
		if (i == LP_BASE_SIZE)
			lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
	}
	lp_push_command(msh, lp);
	return (true);
}

void				line_parser(t_minishel *msh)
{
	t_line_parser lp;

	ft_bzero(&lp, sizeof(t_line_parser));
	if (!(msh->success_exec = lp_loop(msh, &lp)))
		lp_print_error(lp.key);
	ft_lstrev(&msh->commands);
	lp_free(&lp);
}
