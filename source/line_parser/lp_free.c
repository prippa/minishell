#include "line_parser.h"

void		lp_free(t_line_parser *lp)
{
	ft_strdel(&lp->arg);
	ft_lstdel(&lp->args, ft_lstdel_content);
}
