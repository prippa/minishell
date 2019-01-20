#ifndef LP_COMMANDS_H
# define LP_COMMANDS_H

# include "line_parser.h"

# define LP_BASE_SIZE			6
# define LP_DOUBLE_QUOTES_SIZE	2

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

static const char	g_base_cs[LP_BASE_SIZE] =
{
	SPACE_C, DOLLAR_C, SEMICOLON_C, SINGLE_QUOTES_C, DOUBLE_QUOTES_C,
	BACKSLASH_C
};

static const char	g_double_quotes_cs[LP_DOUBLE_QUOTES_SIZE] =
{
	DOLLAR_C, BACKSLASH_C
};

typedef t_bool		(*t_func_cmd)(t_minishel *msh, t_line_parser *lp);

static const		t_func_cmd	g_base_fs[LP_BASE_SIZE] =
{
	lp_space, lp_dollar, lp_semicolon, lp_single_quotes, lp_double_quotes,
	lp_backslash
};

static const		t_func_cmd	g_double_quotes_fs[LP_DOUBLE_QUOTES_SIZE] =
{
	lp_dollar, lp_backslash
};

void				lp_quote_read(t_minishel *msh, t_line_parser *lp,
						t_func_cmd func);

#endif