/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_single_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:56:46 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:56:48 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

void	lp_single_quotes(t_line_parser *lp)
{
	char	*start;
	size_t	len;

	len = 0;
	start = &g_msh.line[++g_msh.i];
	while (g_msh.line[g_msh.i] != SINGLE_QUOTES_C)
	{
		++len;
		++g_msh.i;
	}
	if (len)
		lp_write_to_arg_buf_str(lp, start, len);
}
