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

void		msh_execute_command(t_msh *msh)
{
	char		**args;
	uint32_t	i;

	SAFE_ALLOC(msh, msh_error_exit, args, ft_strsplit, msh->line, ' ');
	i = -1;
	while (++i < MSH_CMD_SIZE)
		if (!ft_strcmp(args[0], g_cmd_string[i]))
			g_cmd_func[i](msh, &args[1]);
	ft_arrdel(&args);
}
