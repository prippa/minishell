#include "line_parser.h"

void	lp_error_exit(t_minishel *msh, t_line_parser *lp,
			const char *message)
{
	lp_free(lp);
	msh_error_exit(msh, message);
}
