/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_static_arr.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:20:15 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 20:20:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_STATIC_ARR_H
# define BUILTIN_STATIC_ARR_H

# include "builtin.h"

typedef void		(*t_func_cmd)(char **args);
static const		t_func_cmd	g_cmd_func[MSH_CMD_SIZE] =
{
	msh_cd, msh_echo, msh_env, msh_setenv,
	msh_unsetenv, msh_exit
};

static const char	*g_cmd_string[MSH_CMD_SIZE] =
{
	CD_CMD, ECHO_CMD, ENV_CMD, SETENV_CMD,
	UNSETENV_CMD, EXIT_CMD
};

#endif