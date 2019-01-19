/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_commands.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:02:07 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 19:02:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_COMMANDS_H
# define MSH_COMMANDS_H

# include "minishell.h"

# define MSH_CMD_SIZE	6

static const char	*g_cmd_string[MSH_CMD_SIZE] =
{
	"cd", "echo", "env", "setenv",
	"unsetenv", "exit"
};

typedef void		(*t_func_cmd)(t_minishel *msh, const char **args);
static const		t_func_cmd	g_cmd_func[MSH_CMD_SIZE] =
{
	msh_cd, msh_echo, msh_env, msh_setenv,
	msh_unsetenv, msh_exit
};

#endif
