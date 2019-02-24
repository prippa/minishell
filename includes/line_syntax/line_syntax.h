/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_syntax.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:46:42 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:46:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_SYNTAX_H
# define LINE_SYNTAX_H

# include "minishell.h"

typedef struct	s_line_syntax
{
	t_bool		semi_flag;
}				t_line_syntax;

t_bool			ls_read_new_line(t_bool nl_f);
t_bool			ls_backslash_check(t_line_syntax *ls);
t_bool			ls_dobule_q_check(t_line_syntax *ls);
t_bool			ls_single_q_check(t_line_syntax *ls);
t_bool			ls_semi_check(t_line_syntax *ls);

#endif
