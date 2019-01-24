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
# include "syntax_characters.h"

# define ARG_BUF_SIZE	4096

enum
{
	SEMI_SYNTAX_KEY = 1
};

typedef struct	s_line_parser
{
	t_list		*args;
	size_t		args_size;
	char		arg_buf[ARG_BUF_SIZE + 1];
	size_t		arg_buf_len;
	char		*arg;
	size_t		arg_len;
	uint16_t	key;
}				t_line_parser;

void			lp_error_exit(t_minishel *msh, t_line_parser *lp,
					const char *message);
void			lp_print_error(uint16_t key);
void			lp_free(t_line_parser *lp);

void			lp_join_to_arg(t_minishel *msh, t_line_parser *lp,
					const char *src, size_t len);
void			lp_write_to_arg_buf_str(t_minishel *msh, t_line_parser *lp,
					const char *src, size_t len);
void			lp_write_to_arg_buf_char(t_minishel *msh, t_line_parser *lp,
					char c);

void			lp_push_command(t_minishel *msh, t_line_parser *lp);
void			lp_push_arg(t_minishel *msh, t_line_parser *lp);

t_bool			lp_new_line(t_minishel *msh, t_line_parser *lp, t_bool nl_f);

typedef t_bool	(*t_func_cmd)(t_minishel *msh, t_line_parser *lp);
t_bool			lp_dollar(t_minishel *msh, t_line_parser *lp);
t_bool			lp_backslash(t_minishel *msh, t_line_parser *lp);
t_bool			lp_single_quotes(t_minishel *msh, t_line_parser *lp);
t_bool			lp_double_quotes(t_minishel *msh, t_line_parser *lp);
t_bool			lp_space(t_minishel *msh, t_line_parser *lp);
t_bool			lp_semicolon(t_minishel *msh, t_line_parser *lp);
t_bool			lp_tilde(t_minishel *msh, t_line_parser *lp);

#endif
