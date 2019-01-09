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

static void		msh_set_new_env(t_msh *msh, t_env *e)
{
	t_list2	*new_obj;

	if (!(new_obj = ft_lst2new(e, sizeof(t_env))))
		msh_error_exit(msh, MALLOC_ERR);
	ft_lst2_push_back(&msh->env_start, &msh->env_end, new_obj);
}

static t_bool	msh_edit_env(t_msh *msh, t_env *e)
{
	t_env	*env_obj_for_edit;

	if ((env_obj_for_edit = msh_env_get_obj_by_name(msh->env_start, e->name)))
	{
		ft_strdel(&env_obj_for_edit->arg);
		env_obj_for_edit->arg = e->arg;
		return (true);
	}
	return (false);
}

static void		msh_edit_or_set_new_env(t_msh *msh, char *str)
{
	size_t	separate_index;
	t_env	e;

	separate_index = ft_strchr(str, '=') - str;
	if (!(e.name = ft_strsub(str, 0, separate_index)))
		msh_error_exit(msh, MALLOC_ERR);
	if (!(e.arg = ft_strdup(&str[separate_index + 1])))
		msh_error_exit(msh, MALLOC_ERR);
	if (!msh_edit_env(msh, &e))
		msh_set_new_env(msh, &e);
	else
		ft_strdel(&e.name);
}

void			msh_setenv_one_arg(t_msh *msh, char *str)
{
	if (*str != '=' && ft_strchr(str, '='))
		msh_edit_or_set_new_env(msh, str);
	else
	{
		ft_dprintf(2, MSH_SETENV_INVALID_ARG, str);
		msh->execute_flag = false;
	}
}

void			msh_setenv(t_msh *msh, char **args)
{
	if (!*args)
	{
		msh_print_error(msh, MSH_SETENV_USG);
		return ;
	}
	while (*args)
		msh_setenv_one_arg(msh, *args++);
}
