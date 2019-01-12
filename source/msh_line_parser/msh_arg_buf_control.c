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

static void	msh_double_join(t_msh *msh, t_line_parser *prs,
	const char *s, size_t s_len)
{
	char *buf_plus_s;

	if (!(buf_plus_s = (char *)ft_memjoin(prs->arg_buf, s,
		prs->arg_buf_len, s_len)))
			msh_error_exit(msh, MALLOC_ERR);
	if (!ft_memjoin_free((void **)&prs->arg, buf_plus_s,
		prs->arg_len, prs->arg_buf_len + s_len))
			msh_error_exit(msh, MALLOC_ERR);
	ft_strdel(&buf_plus_s);
	prs->arg_len += (prs->arg_buf_len + s_len);
	prs->arg_buf_len = 0;
	*prs->arg_buf = 0;
}

void		msh_write_to_arg_buf(t_msh *msh, t_line_parser *prs,
	const char *s)
{
	size_t s_len;

	s_len = ft_strlen(s);
	if (s_len > ARG_BUF_SIZE)
		msh_double_join(msh, prs, s, s_len);
}
