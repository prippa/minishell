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

#include "commands.h"

void		msh_execute_cmds(t_msh *msh)
{
	t_cmd		*cm;
	uint32_t	i;

	while (msh->cmd_start)
	{
		cm = (t_cmd *)msh->cmd_start->content;
		ft_str_to_lower(&cm->args[0]);
		i = -1;
		while (++i < MSH_CMD_SIZE)
			if (!ft_strcmp(cm->args[0], g_cmd_string[i]))
				g_cmd_func[i](msh, &cm->args[1]);
		ft_lst2_pop_front(&msh->cmd_start, &msh->cmd_end, msh_del_cmd_list);
	}
}
