#include "minishell.h"

void		msh_error_exit(t_msh *msh, const char *message)
{
	ft_dprintf(2, MSH_ERR, message);
	msh_free(msh);
	exit(-1);
}
