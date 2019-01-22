#include "line_lexer.h"
#include <readline/readline.h>
#include <readline/history.h>

t_bool		lx_read_new_line(t_minishel *msh, t_bool nl_f)
{
	char *new_line;

	if (!(new_line = readline("> ")))
		return (false);
	if (nl_f)
	{
		if (!(ft_strjoin_free(&msh->line, "\n", ft_strlen(msh->line), 1)))
			msh_error_exit(msh, MALLOC_ERR);
	}
	if (!(ft_strjoin_free(&msh->line, new_line,
		ft_strlen(msh->line), ft_strlen(new_line))))
		msh_error_exit(msh, MALLOC_ERR);
	ft_strdel(&new_line);
	return (true);
}
