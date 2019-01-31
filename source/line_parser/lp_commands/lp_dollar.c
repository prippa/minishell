#include "line_parser.h"

void	lp_dollar(t_line_parser *lp)
{
	const char	*s;
	size_t		len;

	if (!ft_isalnum_in_case(g_msh.line[g_msh.i + 1]))
	{
		lp_write_to_arg_buf_char(lp, g_msh.line[g_msh.i]);
		return ;
	}
	s = &g_msh.line[++g_msh.i];
	if (ft_isalpha_in_case(g_msh.line[g_msh.i]))
	{
		len = 1;
		while (ft_isalnum_in_case(g_msh.line[++g_msh.i]))
			++len;
		if ((s = msh_getenv_value_by_key(g_msh.env_start, s, len)))
			lp_write_to_arg_buf_str(lp, s, ft_strlen(s));
		--g_msh.i;
	}
}
