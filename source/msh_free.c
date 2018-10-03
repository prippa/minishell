#include "minishell.h"

static void	msh_del_env_list(void *content, size_t content_size)
{
	t_env *e;

	e = (t_env *)content;
	(void)content_size;
	free(e->name);
	free(e->arg);
	free(content);
}

void		msh_del_cmd_list(void *content, size_t content_size)
{
	t_cmd *cm;

	cm = (t_cmd *)content;
	(void)content_size;
	ft_arrdel(&cm->args);
	free(content);
}

void		msh_free(t_msh *msh)
{
	ft_lst2del(&msh->env_start, &msh->env_end, msh_del_env_list);
	ft_lst2del(&msh->cmd_start, &msh->cmd_end, msh_del_cmd_list);
	ft_strdel(&msh->line);
}
