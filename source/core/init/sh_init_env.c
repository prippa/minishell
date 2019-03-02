/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:32:58 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 12:32:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"
#include "environ_manipulation.h"

static void	sh_set_shell_lvl(void)
{
	char		*value;

	if ((value = env_get_vlu_by_key(g_sh.env_start, SHELL_LVL_ENV)))
	{
		if (!(value = ft_itoa_max(ft_atoi_max(value) + 1)))
			sh_fatal_err(MALLOC_ERR);
		env_set(&g_sh.env_start, &g_sh.env_end,
			&(t_env){.key = SHELL_LVL_ENV, .value = value}, true);
		ft_memdel((void **)&value);
	}
	else
		env_set(&g_sh.env_start, &g_sh.env_end,
			&(t_env){.key = SHELL_LVL_ENV, .value = "1"}, true);
}

static void	sh_set_pwd(void)
{
	char *value;

	if (!(value = env_get_vlu_by_key(g_sh.env_start, PWD_ENV)))
	{
		if (!(value = getcwd(NULL, 0)))
			sh_fatal_err(GETCWD_FAILED);
		env_set(&g_sh.env_start, &g_sh.env_end,
			&(t_env){.key = PWD_ENV, .value = value}, true);
	}
}

void		sh_init_env(void)
{
	extern char	**environ;

	if (*environ)
		sh_setenv(environ);
	env_set(&g_sh.env_start, &g_sh.env_end,
		&(t_env){.key = SHELL_ENV, .value = SHELL_NAME}, true);
	sh_set_pwd();
	sh_set_shell_lvl();
}
