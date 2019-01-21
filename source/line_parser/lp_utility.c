#include "lp_commands.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <readline/readline.h>
#include <readline/history.h>

#define LP	"line parser : "

void		lp_free(t_line_parser *lp)
{
	ft_strdel(&lp->arg);
	ft_lstdel(&lp->args, ft_lstdel_content);
}

void		lp_error_exit(t_minishel *msh, t_line_parser *lp,
			const char *message)
{
	lp_free(lp);
	msh_error_exit(msh, message);
}

void		lp_print_error(uint16_t key)
{
	if (key == SEMI_SYNTAX_KEY)
		ft_dprintf(STDERR_FILENO,
			"%ssyntax error near unexpected token '%c'\n", LP, SEMICOLON_C);
	else if (key == UNEXPECTED_EOF)
		ft_dprintf(STDERR_FILENO,
			"\n%sunexpected EOF\n", LP);
}

t_bool		lp_new_line(t_minishel *msh, t_line_parser *lp, t_bool nl_f)
{
	char *new_line;

	if (!(new_line = readline("> ")))
		return (false);
	if (nl_f)
	{
		if (!(ft_strjoin_free(&msh->line, "\n", ft_strlen(msh->line), 1)))
			lp_error_exit(msh, lp, MALLOC_ERR);
	}
	if (!(ft_strjoin_free(&msh->line, new_line,
		ft_strlen(msh->line), ft_strlen(new_line))))
		lp_error_exit(msh, lp, MALLOC_ERR);
	ft_strdel(&new_line);
	return (true);
}
