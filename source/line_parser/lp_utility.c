#include "line_parser.h"

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
}
