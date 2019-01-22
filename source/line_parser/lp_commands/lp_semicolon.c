#include "line_parser.h"

t_bool		lp_semicolon(t_minishel *msh, t_line_parser *lp)
{
	if (!lp->args && !lp->arg_len && !lp->arg_buf_len)
	{
		lp->key = SEMI_SYNTAX_KEY;
		return (false);
	}
	lp_push_command(msh, lp);
	return (true);
}
