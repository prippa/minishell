#include "line_parser.h"

t_bool		lp_backslash(t_minishel *msh, t_line_parser *lp)
{
	++msh->i;
	if (msh->line[msh->i])
		lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
	else
	{
		msh->line[--msh->i] = 0;
		if (!ft_strdup_free(&msh->line, msh->line))
			lp_error_exit(msh, lp, MALLOC_ERR);
		if (!lp_new_line(msh, lp, false))
		{
			lp->key = UNEXPECTED_EOF;
			return (false);
		}
		--msh->i;
	}
	return (true);
}
