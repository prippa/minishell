/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:12:06 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:12:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "minishell.h"

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

t_bool			rl_line_syntax(t_read_line *rl);
t_bool			ls_backslash_check(t_read_line *rl, t_line_syntax *ls);
t_bool			ls_dobule_q_check(t_read_line *rl, t_line_syntax *ls);
t_bool			ls_single_q_check(t_read_line *rl, t_line_syntax *ls);
t_bool			ls_semi_check(t_read_line *rl, t_line_syntax *ls);

#endif
