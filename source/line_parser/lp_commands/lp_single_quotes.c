#include "line_parser.h"

void	lp_single_quotes(t_line_parser *lp)
{
	char	*start;
	size_t	len;

	len = 0;
	start = &g_msh.line[++g_msh.i];
	while (g_msh.line[g_msh.i] != SINGLE_QUOTES_C)
	{
		++len;
		++g_msh.i;
	}
	if (len)
		lp_write_to_arg_buf_str(lp, start, len);
}
