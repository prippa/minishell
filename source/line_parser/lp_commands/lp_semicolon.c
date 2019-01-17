#include "lp_commands.h"

#define LP_SNTX_ERR "syntax error near unexpected token ';'"

void		lp_semicolon(t_minishel *msh, t_line_parser *lp)
{
	if (!lp->args && !lp->arg_len && !lp->arg_buf_len)
		lp_error_exit(msh, lp, LP_SNTX_ERR);
	lp_push_command(msh, lp);
	lp->f.prev_cmd = SEMICOLON_C;
}
