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

void	msh_unsetenv_one_value(t_minishel *msh, const char *value)
{
	t_list2		*t;

	if (!(t = msh_env_get_obj_by_name(msh->env_start, value, ft_strlen(value))))
	{
		ft_dprintf(2, MSH_UNSETENV_NO_NAME, value);
		msh->execute_flag = false;
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
		msh_unsetenv_one_value(msh, *args++);
}
