/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:41:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:41:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lp_commands.h"

static void	lp_loop(t_minishel *msh, t_line_parser *lp)
{
	size_t i;

	msh->i = -1;
	while (msh->line[++msh->i])
	{
		i = -1;
		while (++i < LP_BASE_SIZE)
			if (msh->line[msh->i] == g_base_cs[i])
				g_base_fs[i](msh, lp);
		if (i == LP_BASE_SIZE)
		{
			lp_write_to_arg_buf_char(msh, lp, msh->line[msh->i]);
			lp->f.prev_cmd = BASE_C;
		}
		lp->f.prev_char = msh->line[msh->i];
	}
	lp_push_command(msh, lp);
}

static void	lp_init(t_minishel *msh, t_line_parser *lp)
{
	ft_bzero(lp, sizeof(t_line_parser));
}

void print_args(t_list *elem)
{
	t_command *cmd;

	cmd = (t_command *)elem->content;
	ft_putchar('\n');
	printf("LLLL\n");
	if (cmd->args)
		printf("YEA!\n");

	// ft_putarr(cmd->args);
	ft_putchar('\n');
}
void		msh_line_parser(t_minishel *msh)
{
	t_line_parser lp;

	lp_init(msh, &lp);
	lp_loop(msh, &lp);
	// ft_lstiter(msh->commands, print_args);
	lp_free(&lp);
	// char	**arr;
	// size_t	i;
	// t_list2	*start;

	// i = -1;
	// arr = (char **)malloc(sizeof(char *) * msh->env_size + 1);
	// start = msh->env_start;
	// while (++i < msh->env_size)
	// {
	// 	arr[i] = ((t_env *)start->content)->env;
	// 	start = start->next;
	// }
	// arr[i] = NULL;
	// ft_putarr(arr);
	// free(arr);
	// ft_printf("%s\n", msh->line);
}
