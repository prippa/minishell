/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:02 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define SH_UNSETENV_USG		"unsetenv: usage: unsetenv [key] ..."
#define SH_UNSETENV_NO_NAME	"unsetenv: '%s' not found"

void	sh_unsetenv_one_env(const char *env)
{
	t_list2		*t;

	if (!(t = sh_getenv_obj_by_key(env, ft_strlen(env))))
	{
		PRINT_ERR(EXIT_FAILURE, SH_UNSETENV_NO_NAME, env);
		return ;
	}
	ft_lst2del_by_obj(&g_sh.env_start, &g_sh.env_end, t, sh_del_env_list);
	--g_sh.env_size;
}

void	sh_unsetenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(EXIT_FAILURE, SH_UNSETENV_USG, NULL);
		return ;
	}
	while (*args)
		sh_unsetenv_one_env(*args++);
}
