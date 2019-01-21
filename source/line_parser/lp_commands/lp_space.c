#include "lp_commands.h"

t_bool		lp_space(t_minishel *msh, t_line_parser *lp)
{
	if (lp->arg_len || lp->arg_buf_len)
		lp_push_arg(msh, lp);
	return (true);
}
