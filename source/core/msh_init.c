#include "minishell.h"

t_bool		g_ok;
t_minishel	g_msh;

void	msh_init(void)
{
	extern char	**environ;

	ft_bzero(&g_msh, sizeof(t_minishel));
	msh_setenv(environ);
	g_ok = true;
	msh_update_curent_dir_name();
	msh_update_prompt();
}
