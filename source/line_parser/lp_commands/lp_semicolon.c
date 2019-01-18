#include "lp_commands.h"

t_bool		lp_semicolon(t_minishel *msh, t_line_parser *lp)
{
	if (!lp->args && !lp->arg_len && !lp->arg_buf_len)
	{
		lp_print_error(lp, SEMI_SYNTAX_KEY);
		return (false);
	}
	lp_push_command(msh, lp);
	lp->f.prev_cmd = SEMICOLON_C;
	return (true);
}
