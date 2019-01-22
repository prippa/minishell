#include "line_parser.h"

static t_bool	lp_tilde_valid_prev(const char *line, size_t i)
{
	if (!(i + 1) || line[i] == SPACE_C)
		return (true);
	return (false);
}

static t_bool	lp_tilde_valid_next(const char *line, size_t i)
{
	if (!line[i] || line[i] == SPACE_C || line[i] == UNIX_PATH_SEPARATOR)
		return (true);
	return (false);
}

t_bool			lp_tilde(t_minishel *msh, t_line_parser *lp)
{
	const char	*home;

	if (lp_tilde_valid_prev(msh->line, msh->i - 1) &&
		lp_tilde_valid_next(msh->line, msh->i + 1))
	{
		if ((home = msh_env_get_value_by_key(msh->env_start,
			HOME_ENV, ft_strlen(HOME_ENV))))
			lp_write_to_arg_buf_str(msh, lp, home, ft_strlen(home));
	}
	else
		lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
	return (true);
}
