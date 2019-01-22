#ifndef LINE_PARSER_H
# define LINE_PARSER_H

# include "minishell.h"
# include "syntax_characters.h"

t_bool		lx_read_new_line(t_minishel *msh, t_bool nl_f);
t_bool		lx_backslash_check(t_minishel *msh);
t_bool		lx_dobule_q_check(t_minishel *msh);
t_bool		lx_single_q_check(t_minishel *msh);

# endif
