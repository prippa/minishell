#include "line_parser.h"

static void	lp_build_command(t_minishel *msh, t_line_parser *lp,
				t_command *cmd)
{
	t_list		*args;
	uint32_t	i;

	if (!(cmd->args = (char **)ft_memalloc(sizeof(char *) * lp->args_size + 1)))
		lp_error_exit(msh, lp, MALLOC_ERR);
	args = lp->args;
	i = -1;
	while (args)
	{
		cmd->args[++i] = ft_strdup((char *)args->content);
		args = args->next;
	}
}

void		lp_push_command(t_minishel *msh, t_line_parser *lp)
{
	t_command	cmd;
	t_list		*l;

	lp_push_arg(msh, lp);
	if (!lp->args)
		return ;
	ft_lstrev(&lp->args);
	lp_build_command(msh, lp, &cmd);
	if (!(l = ft_lstnew(&cmd, sizeof(t_command))))
		lp_error_exit(msh, lp, MALLOC_ERR);
	ft_lstadd(&msh->commands, l);
	ft_lstdel(&lp->args, ft_lstdel_content);
	lp->args_size = 0;
}

void		lp_push_arg(t_minishel *msh, t_line_parser *lp)
{
	t_list *new_obj;

	if (lp->arg_buf_len)
		lp_join_to_arg(msh, lp, lp->arg_buf, lp->arg_buf_len);
	if (lp->arg_len)
	{
		if (!(new_obj = ft_lstnew(lp->arg, ft_strlen(lp->arg) + 1)))
			lp_error_exit(msh, lp, MALLOC_ERR);
		ft_lstadd(&lp->args, new_obj);
		++lp->args_size;
		ft_strdel(&lp->arg);
		*lp->arg_buf = 0;
		lp->arg_len = 0;
		lp->arg_buf_len = 0;
	}
}
