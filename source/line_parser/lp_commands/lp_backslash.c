#include "line_parser.h"

void	lp_backslash(t_line_parser *lp)
{
	lp_write_to_arg_buf_char(lp, g_msh.line[++g_msh.i]);
}
