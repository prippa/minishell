#include "lp_commands.h"

static size_t	lp_single_quotes_get_len(t_minishel *msh, t_line_parser *lp)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = msh->i;
	while (msh->line[i] && msh->line[i] != SINGLE_QUOTES_C)
	{
		++i;
		++len;
	}
	if (!msh->line[i])
	{
		if (len)
		{
			lp_write_to_arg_buf_str(msh, lp, &msh->line[msh->i], len);
			msh->i += len;
		}
		lp_quote_read(msh, lp, &lp_single_quotes);
		return (0);
	}
	return (len);
}

t_bool		lp_single_quotes(t_minishel *msh, t_line_parser *lp)
{
	size_t len;

	++msh->i;
	if ((len = lp_single_quotes_get_len(msh, lp)))
	{
		lp_write_to_arg_buf_str(msh, lp, &msh->line[msh->i], len);
		msh->i += len;
	}
	return (true);
}
