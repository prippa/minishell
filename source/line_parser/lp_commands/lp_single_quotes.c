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
#include "syntax_characters.h"

void	lp_single_quotes(t_line_parser *lp)
{
	char	*start;
	size_t	len;

	len = 0;
	start = &g_sh.line[++g_sh.i];
	while (g_sh.line[g_sh.i] != SINGLE_QUOTES_C)
	{
		++len;
		++g_sh.i;
	}
	if (len)
		lp_write_to_arg_buf_str(lp, start, len);
}
