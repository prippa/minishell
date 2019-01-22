#include "line_lexer.h"

t_bool		lx_backslash_check(t_minishel *msh)
{
	if (!msh->line[++msh->i])
	{
		msh->line[--msh->i] = 0;
		if (!ft_strdup_free(&msh->line, msh->line))
			msh_error_exit(msh, MALLOC_ERR);
		if (!(lx_read_new_line(msh, false)))
			return (false);
		--msh->i;
	}
	return (true);
}

t_bool		lx_dobule_q_check(t_minishel *msh)
{
	while (true)
	{
		if (!msh->line[++msh->i] && !lx_read_new_line(msh, true))
			return (false);
		if (msh->line[msh->i] == BACKSLASH_C)
			lx_backslash_check(msh);
		else if (msh->line[msh->i] == DOUBLE_QUOTES_C)
			return (true);
	}
}

t_bool		lx_single_q_check(t_minishel *msh)
{
	while (true)
	{
		if (!msh->line[++msh->i] && !lx_read_new_line(msh, true))
			return (false);
		if (msh->line[msh->i] == SINGLE_QUOTES_C)
			return (true);
	}
}
