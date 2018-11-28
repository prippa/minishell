/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:56 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		msh_set_new_env(t_msh *msh, const char *arg, size_t si)
{
	t_list2	*new_obj;
	t_env	e;

	if (!(e.name = ft_strdup(arg)))
		msh_error_exit(msh, MALLOC_ERR);
	if (!(e.arg = ft_strdup(&arg[si + 1])))
		msh_error_exit(msh, MALLOC_ERR);
	if (!(new_obj = ft_lst2new(&e, sizeof(t_env))))
		msh_error_exit(msh, MALLOC_ERR);
	ft_lst2_push_back(&msh->env_start, &msh->env_end, new_obj);
}

static t_bool	msh_edit_env(t_msh *msh, const char *arg, size_t si)
{
	t_list2 *lst;
	t_env	*e;

	lst = msh->env_start;
	while (lst)
	{
		e = (t_env *)lst->content;
		if (!ft_strcmp(e->name, arg))
		{
			if (!(ft_strdup_free(&e->arg, &arg[si + 1])))
				msh_error_exit(msh, MALLOC_ERR);
			return (false);
		}
		lst = lst->next;
	}
	return (true);
}

static void		msh_edit_or_set_new_env(t_msh *msh, char *arg)
{
	size_t	separate_index;

	separate_index = ft_strchr(arg, '=') - arg;
	arg[separate_index] = 0;
	if (msh_edit_env(msh, arg, separate_index))
		msh_set_new_env(msh, arg, separate_index);
}

static void		msh_print_setenv_invalid_arg(t_msh *msh, const char *arg)
{
	ft_dprintf(2, MSH_SETENV_INVALID_ARG, arg);
	msh->execute_flag = false;
}

void			msh_setenv(t_msh *msh, char **args)
{
	if (!*args)
		msh_print_error(msh, MSH_SETENV_USG);
	else
	{
		while (*args)
		{
			if (**args != '=' && ft_strchr(*args, '='))
				msh_edit_or_set_new_env(msh, *args);
			else
				msh_print_setenv_invalid_arg(msh, *args);
			++args;
		}
	}
}
