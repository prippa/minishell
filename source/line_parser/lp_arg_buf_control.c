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

static void	sh_double_join(t_line_parser *lp, const char *src, size_t len)
{
	char *buf_plus_s;

	if (lp->arg_buf_len)
	{
		GET_MEM(MALLOC_ERR, buf_plus_s, ft_strnjoin,
			lp->arg_buf, src, lp->arg_buf_len, len);
	}
	else
		buf_plus_s = (char *)src;
	lp_join_to_arg(lp, buf_plus_s, lp->arg_buf_len + len);
	if (lp->arg_buf_len)
		ft_memdel((void **)&buf_plus_s);
	lp->arg_buf_len = 0;
	*lp->arg_buf = 0;
}

static void	sh_join_cpy(t_line_parser *lp, const char *src, size_t len)
{
	lp_join_to_arg(lp, lp->arg_buf, lp->arg_buf_len);
	ft_strncpy(lp->arg_buf, src, len);
	lp->arg_buf_len = len;
	lp->arg_buf[lp->arg_buf_len] = 0;
}

void		lp_join_to_arg(t_line_parser *lp, const char *src, size_t len)
{
	if (!len)
		return ;
	if (lp->arg)
		ft_strjoin_free(&lp->arg, src, lp->arg_len, len);
	else
		lp->arg = ft_strsub(src, 0, len);
	if (!lp->arg)
		sh_fatal_err(MALLOC_ERR);
	lp->arg_len += len;
}

void		lp_write_to_arg_buf_char(t_line_parser *lp, char c)
{
	if (lp->arg_buf_len + 1 > ARG_BUF_SIZE)
		sh_join_cpy(lp, &c, 1);
	else
	{
		lp->arg_buf[lp->arg_buf_len] = c;
		++lp->arg_buf_len;
	}
}

void		lp_write_to_arg_buf_str(t_line_parser *lp,
				const char *src, size_t len)
{
	if (len > ARG_BUF_SIZE)
		sh_double_join(lp, src, len);
	else if (lp->arg_buf_len + len > ARG_BUF_SIZE)
		sh_join_cpy(lp, src, len);
	else
	{
		ft_strncpy(lp->arg_buf + lp->arg_buf_len, src, len);
		lp->arg_buf_len += len;
		lp->arg_buf[lp->arg_buf_len] = 0;
	}
}
