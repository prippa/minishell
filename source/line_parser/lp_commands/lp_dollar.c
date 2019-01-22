#include "line_parser.h"

t_bool		lp_dollar(t_minishel *msh, t_line_parser *lp)
{
	const char	*s;
	size_t		len;

	if (!ft_isalnum_in_case(msh->line[msh->i + 1]))
	{
		lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
		return (true);
	}
	s = &msh->line[++msh->i];
	if (ft_isalpha_in_case(msh->line[msh->i]))
	{
		len = 1;
		while (ft_isalnum_in_case(msh->line[++msh->i]))
			++len;
		if ((s = msh_env_get_value_by_key(msh->env_start, s, len)))
			lp_write_to_arg_buf_str(msh, lp, s, ft_strlen(s));
		--msh->i;
	}
	return (true);
}
