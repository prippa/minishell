/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_arg_buf_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:47:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:47:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

static void	msh_double_join(t_minishel *msh, t_line_parser *lp,
				const char *src, size_t len)
{
	char *buf_plus_s;

	if (lp->arg_buf_len)
	{
		if (!(buf_plus_s = ft_strjoin(lp->arg_buf, src,
			lp->arg_buf_len, len)))
				lp_error_exit(msh, lp, MALLOC_ERR);
	}
	else
		buf_plus_s = (char *)src;
	lp_join_to_arg(msh, lp, buf_plus_s, lp->arg_buf_len + len);
	if (lp->arg_buf_len)
		ft_strdel(&buf_plus_s);
	lp->arg_buf_len = 0;
	*lp->arg_buf = 0;
}

static void	msh_join_cpy(t_minishel *msh, t_line_parser *lp,
				const char *src, size_t len)
{
	lp_join_to_arg(msh, lp, lp->arg_buf, lp->arg_buf_len);
	ft_strncpy(lp->arg_buf, src, len);
	lp->arg_buf_len = len;
	lp->arg_buf[lp->arg_buf_len] = 0;
}

void		lp_join_to_arg(t_minishel *msh, t_line_parser *lp,
				const char *src, size_t len)
{
	if (!len)
		return ;
	if (lp->arg)
		ft_strjoin_free(&lp->arg, src, lp->arg_len, len);
	else
		lp->arg = ft_strsub(src, 0, len);
	if (!lp->arg)
		lp_error_exit(msh, lp, MALLOC_ERR);
	lp->arg_len += len;
}

void		lp_write_to_arg_buf_char(t_minishel *msh, t_line_parser *lp,
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

void		lp_write_to_arg_buf_str(t_minishel *msh, t_line_parser *lp,
				const char *src, size_t len)
{
	if (len > ARG_BUF_SIZE)
		msh_double_join(msh, lp, src, len);
	else if (lp->arg_buf_len + len > ARG_BUF_SIZE)
		msh_join_cpy(msh, lp, src, len);
	else
	{
		ft_strncpy(lp->arg_buf + lp->arg_buf_len, src, len);
		lp->arg_buf_len += len;
		lp->arg_buf[lp->arg_buf_len] = 0;
	}
}
