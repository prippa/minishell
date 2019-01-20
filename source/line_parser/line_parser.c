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

#include "lp_commands.h"

static t_bool	lp_loop(t_minishel *msh, t_line_parser *lp)
{
	size_t i;

	msh->i = -1;
	while (msh->line[++msh->i])
	{
		i = -1;
		while (++i < LP_BASE_SIZE)
			if (msh->line[msh->i] == g_base_cs[i])
			{
				if (!g_base_fs[i](msh, lp))
					return (false);
				break ;
			}
		if (i == LP_BASE_SIZE)
		{
			lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
			lp->f.prev_cmd = BASE_C;
		}
		lp->f.prev_char = msh->line[msh->i];
	}
	lp_push_command(msh, lp);
	return (true);
}

void			line_parser(t_minishel *msh)
{
	t_line_parser lp;

	ft_bzero(&lp, sizeof(t_line_parser));
	if (!(msh->success_exec = lp_loop(msh, &lp)))
		lp_print_error(lp.f.key);
	ft_lstrev(&msh->commands);
}
