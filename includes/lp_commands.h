#ifndef LP_COMMANDS_H
# define LP_COMMANDS_H

# include "line_parser.h"

# define SPACE_C			' '
# define DOLLAR_C			'$'
# define SEMICOLON_C		';'
# define SINGLE_QUOTES_C	'\''
# define DOUBLE_QUOTES_C	'"'
# define BACKSLASH_C		'\\'

# define BASE_C				'c'

t_bool				lp_dollar(t_minishel *msh, t_line_parser *lp);
t_bool				lp_backslash(t_minishel *msh, t_line_parser *lp);
t_bool				lp_single_quotes(t_minishel *msh, t_line_parser *lp);
t_bool				lp_double_quotes(t_minishel *msh, t_line_parser *lp);
t_bool				lp_space(t_minishel *msh, t_line_parser *lp);
t_bool				lp_semicolon(t_minishel *msh, t_line_parser *lp);

typedef t_bool		(*t_func_cmd)(t_minishel *msh, t_line_parser *lp);

#endif