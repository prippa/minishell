#include "line_parser.h"

t_bool			lp_single_quotes(t_minishel *msh, t_line_parser *lp)
{
	char	*start;
	size_t	len;

	len = 0;
	start = &msh->line[++msh->i];
	while (msh->line[msh->i] != SINGLE_QUOTES_C)
	{
		++len;
		++msh->i;
	}
	if (len)
		lp_write_to_arg_buf_str(msh, lp, start, len);
}
