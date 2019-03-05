/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:12:06 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:12:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# include "shell.h"

typedef struct	s_line_syntax
{
	t_bool		semi_flag;
}				t_line_syntax;

typedef struct	s_read_line
{
	char		*line;
	size_t		i;
	t_bool		new_line_flag;
}				t_read_line;

t_read_line		*rl(void);

t_bool			rl_line_syntax(void);
t_bool			ls_backslash_check(t_line_syntax *ls);
t_bool			ls_dobule_q_check(t_line_syntax *ls);
t_bool			ls_single_q_check(t_line_syntax *ls);
t_bool			ls_semi_check(t_line_syntax *ls);

#endif
