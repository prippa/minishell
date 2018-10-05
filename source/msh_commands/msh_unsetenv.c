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

static void		msh_unsetenv_print_usage(t_msh *msh)
{
	ft_dprintf(2, MSH_UNSETENV_USG);
	msh->execute_flag = false;
}

static void		msh_unsetenv_no_name(t_msh *msh, const char *name)
{
	ft_dprintf(2, MSH_UNSETENV_NO_NAME, name);
	msh->execute_flag = false;
}

static t_bool	msh_unsetenv_del_by_name(t_msh *msh, const char *name)
{
	t_list2 *tmp;
	t_list2 *lst;

	lst = msh->env_start;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (!ft_strcmp(((t_env *)tmp->content)->name, name))
		{
			ft_lst2del_by_obj(&msh->env_start, &msh->env_end,
				tmp, msh_del_env_list);
			return (true);
		}
	}
	return (false);
}

void			msh_unsetenv(t_msh *msh, char **args)
{
	if (!*args)
		msh_unsetenv_print_usage(msh);
	else
	{
		while (*args)
		{
			if (!(msh_unsetenv_del_by_name(msh, *args)))
				msh_unsetenv_no_name(msh, *args);
			++args;
		}
	}
}
