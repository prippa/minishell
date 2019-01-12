/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:49:33 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:49:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PARSER_H
# define LINE_PARSER_H

# include "minishell.h"

# define ARG_BUF_SIZE	4096

typedef struct		s_line_parser
{
	t_command		cmd;
	t_list			*args;
	size_t			args_size;
	char			arg_buf[ARG_BUF_SIZE + 1];
	size_t			arg_buf_len;
	char			*arg;
	size_t			arg_len;
}					t_line_parser;

#endif
