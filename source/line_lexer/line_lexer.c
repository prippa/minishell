#include "line_lexer.h"
#include "ft_printf.h"

#define LX_UNEXPECTED_EOF "\nline_lexer : unexpected EOF\n"
#define LX_CMD_SIZE	3

typedef t_bool		(*t_func_cmd)(t_minishel *msh);
static const		t_func_cmd	g_lx_cmd_f[LX_CMD_SIZE] =
{
	lx_single_q_check, lx_dobule_q_check, lx_backslash_check
};

static const char	g_lx_cmd_c[LX_CMD_SIZE] =
{
	SINGLE_QUOTES_C, DOUBLE_QUOTES_C, BACKSLASH_C
};

static t_bool		line_lexer_loop(t_minishel *msh)
{
	uint8_t	i;

	msh->i = -1;
	while (msh->line[++msh->i])
	{
		i = -1;
		while (++i < LX_CMD_SIZE)
			if (msh->line[msh->i] == g_lx_cmd_c[i])
			{
				if (!g_lx_cmd_f[i](msh))
					return (false);
				break ;
			}
	}
	return (true);
}

void				line_lexer(t_minishel *msh)
{
	if (!(msh->success_exec = line_lexer_loop(msh)))
		ft_dprintf(STDERR_FILENO, LX_UNEXPECTED_EOF);
}
