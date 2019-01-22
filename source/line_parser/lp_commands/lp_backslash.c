#include "line_parser.h"

t_bool		lp_backslash(t_minishel *msh, t_line_parser *lp)
{
	lp_write_to_arg_buf_char(msh, lp, msh->line[++msh->i]);
	return (true);
}
