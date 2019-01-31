/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:02 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MSH_UNSETENV_USG		"unsetenv: usage: unsetenv [key] ...\n"
#define MSH_UNSETENV_NO_NAME	"unsetenv: '%s' not found\n"

void	msh_unsetenv_one_env(const char *env)
{
	t_list2		*t;

	if (!(t = msh_getenv_obj_by_key(g_msh.env_start, env, ft_strlen(env))))
	{
		PRINT_ERR(MSH_UNSETENV_NO_NAME, env);
		return ;
	}
	ft_lst2del_by_obj(&g_msh.env_start, &g_msh.env_end, t, msh_del_env_list);
	--g_msh.env_size;
}

void	msh_unsetenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(MSH_UNSETENV_USG, NULL);
		return ;
	}
	while (*args)
		msh_unsetenv_one_env(*args++);
}
