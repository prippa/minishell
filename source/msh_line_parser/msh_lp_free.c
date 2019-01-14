#include "line_parser.h"

static void	msh_lp_del_args(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		msh_lp_free(t_line_parser *lp)
{
	ft_strdel(&lp->arg);
	ft_lstdel(&lp->args, msh_lp_del_args);
}
