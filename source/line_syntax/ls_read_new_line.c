#include "line_syntax.h"

#define LS_PROMPT	"> "

t_bool		ls_read_new_line(t_bool nl_f)
{
	char	*new_line;
	int32_t	res;

	ft_putstr(LS_PROMPT);
	if (!(res = get_next_line(STDIN_FILENO, &new_line)))
		return (false);
	else if (res == ERR)
		msh_fatal_err(GNL_FAILED);
	if (nl_f)
	{
		if (!(ft_strjoin_free(&g_msh.line, "\n", ft_strlen(g_msh.line), 1)))
			msh_fatal_err(MALLOC_ERR);
	}
	if (!(ft_strjoin_free(&g_msh.line, new_line,
		ft_strlen(g_msh.line), ft_strlen(new_line))))
		msh_fatal_err(MALLOC_ERR);
	ft_strdel(&new_line);
	return (true);
}
