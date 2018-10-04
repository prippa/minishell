/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:34 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// void print_cmds(t_list2 *elem)
// {
// 	ft_putarr(((t_cmd *)elem->content)->args);
// 	ft_putstr(";\n");
// }
void		msh_parse_line(t_msh *msh)
{
	t_list2		*new_obj;
	t_cmd		cmd;
	char		**command_blocks;
	uint32_t	i;

	if (!(command_blocks = ft_strsplit(msh->line, ';')))
		msh_error_exit(msh, MALLOC_ERR);
	i = -1;
	while (command_blocks[++i])
	{
		if (!(cmd.args = ft_strsplit(command_blocks[i], ' ')))
			msh_error_exit(msh, MALLOC_ERR);
		if (*cmd.args)
		{
			if (!(new_obj = ft_lst2new(&cmd, sizeof(t_cmd))))
				msh_error_exit(msh, MALLOC_ERR);
			ft_lst2_push_back(&msh->cmd_start, &msh->cmd_end, new_obj);
		}
		else
			ft_arrdel(&cmd.args);
	}
	ft_arrdel(&command_blocks);

	// ft_lst2iter(msh->cmd_start, print_cmds);
	msh_execute_cmds(msh);
	// chdir(msh->line);
	// if (!(getcwd(msh->curent_dir_path, sizeof(msh->curent_dir_path))))
	// 	msh_error_exit(msh, MSH_GETCWD_ERR);
	// // ft_strcpy(msh->curent_dir_name, ft_strrchr(msh->curent_dir_name, '/') + 1);
	// ft_printf("[%s]\n", msh->curent_dir_path);
}
