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

typedef void		(*t_func_cmd)(t_build *b);
static const		t_func_cmd	g_cmd_func[SH_CMD_SIZE] =
{
	sh_cd, sh_echo, sh_env, sh_setenv,
	sh_unsetenv, sh_exit
};

static const char	*g_cmd_string[SH_CMD_SIZE] =
{
	CD_CMD, ECHO_CMD, ENV_CMD, SETENV_CMD,
	UNSETENV_CMD, EXIT_CMD
};

#endif
