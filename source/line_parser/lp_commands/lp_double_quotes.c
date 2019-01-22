#include "line_parser.h"

static t_bool		lp_dqb_adaptation(char c)
{
	if (c == DOLLAR_C ||
		c == BACKSLASH_C ||
		c == DOUBLE_QUOTES_C)
		return (true);
	return (false);
}

static t_bool		lp_double_quotes_backslash(t_minishel *msh, t_line_parser *lp)
{
	if (lp_dqb_adaptation(msh->line[msh->i + 1]))
		return (lp_backslash(msh, lp));
	else
	{
		lp_write_to_arg_buf_str(msh, lp, &msh->line[msh->i], 2);
		++msh->i;
	}
	return (true);
}

#define LP_DOUBLE_QUOTES_SIZE	2

static const		t_func_cmd	g_double_q_f[LP_DOUBLE_QUOTES_SIZE] =
{
	lp_dollar, lp_double_quotes_backslash
};

static const char	g_double_q_c[LP_DOUBLE_QUOTES_SIZE] =
{
	DOLLAR_C, BACKSLASH_C
};

t_bool				lp_double_quotes(t_minishel *msh, t_line_parser *lp)
{
	uint8_t	i;

	while (msh->line[++msh->i] != DOUBLE_QUOTES_C)
	{
		i = -1;
		while (++i < LP_DOUBLE_QUOTES_SIZE)
			if (msh->line[msh->i] == g_double_q_c[i])
			{
				if (!g_double_q_f[i](msh, lp))
					return (false);
				break ;
			}
		if (i == LP_DOUBLE_QUOTES_SIZE)
			lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
	}
	return (true);
}
