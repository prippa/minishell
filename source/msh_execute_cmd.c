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
static void	msh_execute_command_loop(t_minishel *msh)
{
	t_list	*cmds;
	size_t	i;
	char	**args;

	cmds = msh->commands;
	while (cmds)
	{
		args = ((t_command *)cmds->content)->args;
		i = -1;
		while (++i < MSH_CMD_SIZE)
			if (!ft_strcmp(*args, g_cmd_string[i]))
			{
				g_cmd_func[i](msh, args + 1);
				break ;
			}
		cmds = cmds->next;
	}
}

void		msh_execute_command(t_minishel *msh)
{
	line_parser(msh);
	// print_commands(msh->commands);
	msh_execute_command_loop(msh);
	ft_lstdel(&msh->commands, msh_del_commands_list);
}
