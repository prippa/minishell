#include "minishell.h"

void		msh_parse_line(t_msh *msh)
{
	chdir(msh->line);
	getcwd(msh->curent_dir_name, FILE_NAME_MAX);
	// ft_strcpy(msh->curent_dir_name, ft_strrchr(msh->curent_dir_name, '/') + 1);
	ft_printf("[%s]\n", msh->curent_dir_name);
}
