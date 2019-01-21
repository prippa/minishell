#include "lp_commands.h"

#define LP_DOUBLE_QUOTES_SIZE	2

static const		t_func_cmd	g_double_quotes_fs[LP_DOUBLE_QUOTES_SIZE] =
{
	lp_dollar, lp_backslash
};

static const char	g_double_quotes_cs[LP_DOUBLE_QUOTES_SIZE] =
{
	DOLLAR_C, BACKSLASH_C
};

t_bool				lp_double_quotes(t_minishel *msh, t_line_parser *lp)
{
	(void)msh;
	(void)lp;
	return (true);
}
