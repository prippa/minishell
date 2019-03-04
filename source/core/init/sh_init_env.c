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

static void	sh_set_shell_lvl(t_build *b)
{
	char		*value;

	if ((value = env_get_vlu_by_key(*b->env_start, SHELL_LVL_ENV)))
	{
		GET_MEM(MALLOC_ERR, value, ft_itoa_max, ft_atoi_max(value) + 1);
		env_set(b->env_start, b->env_end, ENV(SHELL_LVL_ENV, value), true);
		ft_memdel((void **)&value);
	}
	else
		env_set(b->env_start, b->env_end, ENV(SHELL_LVL_ENV, "1"), true);
}

static void	sh_set_pwd(t_build *b)
{
	char *value;

	if (!(value = env_get_vlu_by_key(*b->env_start, PWD_ENV)))
	{
		GET_MEM(GETCWD_FAILED, value, getcwd, NULL, 0);
		env_set(b->env_start, b->env_end, ENV(PWD_ENV, value), true);
		ft_memdel((void **)&value);
	}
}

static void	sh_set_path(t_build *b)
{
	if (!env_get_vlu_by_key(*b->env_start, PATH_ENV))
		env_set(b->env_start, b->env_end,
			ENV(PATH_ENV, DEFAULT_BIN_PATH), true);
}

void		sh_init_env(void)
{
	extern char	**environ;
	t_build		b;

	b.env_start = &g_sh.env_start;
	b.env_end = &g_sh.env_end;
	b.args = environ;
	sh_setenv(&b);
	env_set(b.env_start, b.env_end, ENV(SHELL_ENV, SHELL_NAME), true);
	sh_set_pwd(&b);
	sh_set_shell_lvl(&b);
	sh_set_path(&b);
}
