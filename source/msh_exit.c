#include "minishell.h"

void		msh_error_exit(t_msh *msh, const char *message)
{
	ft_dprintf(2, MSH_ERR, message);
	msh_free(msh);
	exit(-1);
}

void		msh_exit(t_msh *msh)
{
	msh_free(msh);
	system("leaks -q minishell");
	exit(0);
}
