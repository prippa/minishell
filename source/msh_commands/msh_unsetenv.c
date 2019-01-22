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
#include "ft_printf.h"

#define MSH_UNSETENV_USG		"unsetenv: usage: unsetenv [key] ...\n"
#define MSH_UNSETENV_NO_NAME	"unsetenv: '%s' not found\n"

void	msh_unsetenv_one_env(t_minishel *msh, const char *env)
{
	t_list2		*t;

	if (!(t = msh_env_get_obj_by_key(msh->env_start, env, ft_strlen(env))))
	{
		ft_dprintf(STDERR_FILENO, MSH_UNSETENV_NO_NAME, env);
		msh->success_exec = false;
		return ;
	}
	ft_lst2del_by_obj(&msh->env_start, &msh->env_end, t, msh_del_env_list);
	--msh->env_size;
}

void	msh_unsetenv(t_minishel *msh, char **args)
{
	if (!*args)
	{
		msh_print_error(msh, MSH_UNSETENV_USG);
		return ;
	}
	while (*args)
		msh_unsetenv_one_env(msh, *args++);
}
