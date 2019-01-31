#ifndef LINE_PARSER_H
# define LINE_PARSER_H

# include "minishell.h"
# include "syntax_characters.h"
# include <stdint.h>

typedef struct	s_line_syntax
{
	t_bool		semi_flag;
}				t_line_syntax;

t_bool		ls_read_new_line(t_bool nl_f);
t_bool		ls_backslash_check(t_line_syntax *ls);
t_bool		ls_dobule_q_check(t_line_syntax *ls);
t_bool		ls_single_q_check(t_line_syntax *ls);
t_bool		ls_semi_check(t_line_syntax *ls);

# endif
