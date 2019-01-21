#include "lp_commands.h"

static t_bool	lp_sub_str_to_buf(t_minishel *msh, t_line_parser *lp)
{
	char	*start;
	size_t	len;

	len = 0;
	start = &msh->line[msh->i];
	while (msh->line[msh->i] && msh->line[msh->i] != SINGLE_QUOTES_C)
	{
		++len;
		++msh->i;
	}
	if (len)
		lp_write_to_arg_buf_str(msh, lp, start, len);
	if (!msh->line[msh->i])
		return (false);
	return (true);
}

t_bool			lp_single_quotes(t_minishel *msh, t_line_parser *lp)
{
	++msh->i;
	while (!lp_sub_str_to_buf(msh, lp))
	{
		if (!lp_new_line(msh, lp, true))
		{
			lp->key = UNEXPECTED_EOF;
			return (false);
		}
	}
	return (true);
}
