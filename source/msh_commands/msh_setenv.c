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
#include "ft_printf.h"

#define MSH_SETENV_USG			"usage: setenv [key=value] ...\n"
#define MSH_SETENV_INVALID_ARG	"'%s' is invalid\n"

static void		msh_edit_or_set_new_env(t_minishel *msh, const char *env)
{
	t_env	new_env;
	t_env	*edit_env;
	t_list2	*obj;

	new_env.index = ft_strchr(env, KEY_VALUE_SEPARATOR) - env;
	if (!(new_env.env = ft_strdup(env)))
		msh_error_exit(msh, MALLOC_ERR);
	if ((obj = msh_env_get_obj_by_name(msh->env_start, env, new_env.index)))
	{
		edit_env = (t_env *)obj->content;
		msh_del_env_body(edit_env);
		ft_memcpy(edit_env, &new_env, sizeof(t_env));
		return ;
	}
	if (!(obj = ft_lst2new(&new_env, sizeof(t_env))))
		msh_error_exit(msh, MALLOC_ERR);
	ft_lst2_push_back(&msh->env_start, &msh->env_end, obj);
	++msh->env_size;
}

void			msh_setenv_one_env(t_minishel *msh, const char *env)
{
	if (*env != KEY_VALUE_SEPARATOR && ft_strchr(env, KEY_VALUE_SEPARATOR))
		msh_edit_or_set_new_env(msh, env);
	else
	{
		ft_dprintf(STDERR_FILENO, MSH_SETENV_INVALID_ARG, env);
		msh->success_exec = false;
	}
}

void			msh_setenv(t_minishel *msh, char **args)
{
	if (!*args)
	{
		msh_print_error(msh, MSH_SETENV_USG);
		return ;
	}
	while (*args)
		msh_setenv_one_env(msh, *args++);
}
