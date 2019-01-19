/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:16 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_commands.h"
#include "ft_printf.h"
#define MSH_CMD_NOT_FOUND "%s: command not found\n"
void print_commands(t_list *commands)
{
	size_t i;

	i = 1;
	while (commands)
	{
		char **command = ((t_command *)commands->content)->args;
		ft_printf("Command - %d [%s] {", i, *command);
		while (*(++command))
			ft_printf("%s, ", *command);
		ft_printf("}\n");
		++i;
		commands = commands->next;
	}
}

static void		msh_execute_command_loop(t_minishel *msh)
{
	t_list		*cmds;
	const char	**args;

	cmds = msh->commands;
	while (cmds)
	{
		args = (const char **)((t_command *)cmds->content)->args;
		if (!msh_base_cmd_search(msh, args)
			&& !msh_full_path_cmd_search(msh, *args, args)
			&& !msh_env_path_cmd_search(msh, args))
		{
			ft_dprintf(STDERR_FILENO, MSH_CMD_NOT_FOUND, *args);
			msh->success_exec = false;
		}
		cmds = cmds->next;
	}
}

void			msh_execute_command(t_minishel *msh)
{
	line_parser(msh);
	// print_commands(msh->commands);
	if (msh->success_exec)
		msh_execute_command_loop(msh);
	ft_lstdel(&msh->commands, msh_del_commands_list);
}
