/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:57:09 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:57:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "builtin.h"
#include "messages.h"
#include "environ_manipulation.h"

static char	**lp_get_command(t_line_parser *lp)
{
	size_t	i;
	char	**args;
	t_list	*args_lst;

	GET_MEM(MALLOC_ERR, args, ft_memalloc,
		sizeof(char *) * (lp->args_size + 1));
	args_lst = lp->args;
	i = -1;
	while (args_lst)
	{
		args[++i] = (char *)args_lst->content;
		args_lst = args_lst->next;
	}
	return (args);
}

static void	lp_run_command(char **args)
{
	t_build	b;

	b.env_start = &sh()->env_start;
	b.env_end = &sh()->env_end;
	b.args = args;
	env_set(b.env_start, b.env_end, ENV(PREV_CMD_ENV, *b.args), true);
	sh_process_cmd(&b, SHELL_NAME ": ");
}

void		lp_push_command(t_line_parser *lp)
{
	char	**args;

	lp_push_arg(lp);
	if (!lp->args)
		return ;
	ft_lstrev(&lp->args);
	args = lp_get_command(lp);
	lp_run_command(args);
	ft_arrdel(&args);
	ft_lstdel(&lp->args, NULL);
	lp->args_size = 0;
}

void		lp_push_arg(t_line_parser *lp)
{
	t_list *new_obj;

	if (lp->arg_buf_len)
		lp_join_to_arg(lp, lp->arg_buf, lp->arg_buf_len);
	if (lp->arg_len)
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_lstnew, lp->arg, 0);
		ft_lstadd(&lp->args, new_obj);
		++lp->args_size;
		lp->arg = NULL;
		*lp->arg_buf = 0;
		lp->arg_len = 0;
		lp->arg_buf_len = 0;
	}
}
