/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_arg_buf_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:47:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:47:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

static void	msh_double_join(t_minishel *msh, t_line_parser *lp,
				const char *s, size_t len)
{
	char *buf_plus_s;

	if (lp->arg_buf_len)
	{
		if (!(buf_plus_s = (char *)ft_strjoin(lp->arg_buf, s,
			lp->arg_buf_len, len)))
				msh_lp_error_exit(msh, lp, MALLOC_ERR);
	}
	else if (!(buf_plus_s = ft_strsub(s, 0, len)))
		msh_lp_error_exit(msh, lp, MALLOC_ERR);
	if (!ft_strjoin_free(&lp->arg, buf_plus_s,
		lp->arg_len, lp->arg_buf_len + len))
			msh_lp_error_exit(msh, lp, MALLOC_ERR);
	ft_strdel(&buf_plus_s);
	lp->arg_len += lp->arg_buf_len + len;
	lp->arg_buf_len = 0;
	*lp->arg_buf = 0;
}

static void	msh_join_cpy(t_minishel *msh, t_line_parser *lp,
				const char *s, size_t len)
{
	if (!ft_strjoin_free(&lp->arg, lp->arg_buf,
		lp->arg_len, lp->arg_buf_len))
			msh_lp_error_exit(msh, lp, MALLOC_ERR);
	lp->arg_len += lp->arg_buf_len;
	ft_strncpy(lp->arg_buf, s, len);
	lp->arg_buf_len = len;
}

static void msh_cpy(t_line_parser *lp, const char *s, size_t len)
{
	ft_strncpy(lp->arg_buf, s, len);
	lp->arg_buf_len += len;
}

void		msh_write_to_arg_buf_char(t_minishel *msh, t_line_parser *lp,
				char c)
{
	if (lp->arg_buf_len + 1 > ARG_BUF_SIZE)
		msh_join_cpy(msh, lp, &c, 1);
	else
	{
		lp->arg_buf[lp->arg_buf_len] = c;
		++lp->arg_buf_len;
	}
}

void		msh_write_to_arg_buf_str(t_minishel *msh, t_line_parser *lp,
				const char *s, size_t len)
{
	if (len > ARG_BUF_SIZE)
		msh_double_join(msh, lp, s, len);
	else if (lp->arg_buf_len + len > ARG_BUF_SIZE)
		msh_join_cpy(msh, lp, s, len);
	else
		msh_cpy(lp, s, len);
}
