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

#define MSH_SETENV_USG			"setenv: usage: setenv [key=value] ...\n"
#define MSH_SETENV_INVALID_ARG	"setenv: '%s' not a valid identifier\n"

static void		msh_edit_or_set_new_env(const char *env)
{
	t_env	new_env;
	t_env	*edit_env;
	t_list2	*obj;

	new_env.index = ft_strchr(env, KEY_VALUE_SEPARATOR) - env;
	if (!(new_env.env = ft_strdup(env)))
		msh_fatal_err(MALLOC_ERR);
	if ((obj = msh_getenv_obj_by_key(g_msh.env_start, env, new_env.index)))
	{
		edit_env = (t_env *)obj->content;
		msh_del_env_body(edit_env);
		ft_memcpy(edit_env, &new_env, sizeof(t_env));
		return ;
	}
	if (!(obj = ft_lst2new(&new_env, sizeof(t_env))))
		msh_fatal_err(MALLOC_ERR);
	ft_lst2_push_back(&g_msh.env_start, &g_msh.env_end, obj);
	++g_msh.env_size;
}

static t_bool	msh_setenv_valid(const char *env)
{
	if (ft_isalpha_in_case(*env) && ft_strchr(env, KEY_VALUE_SEPARATOR))
	{
		while (*(++env) != KEY_VALUE_SEPARATOR)
			if (!ft_isalnum_in_case(*env))
				return (false);
		return (true);
	}
	return (false);
}

void			msh_setenv_one_env(const char *env)
{
	if (msh_setenv_valid(env))
		msh_edit_or_set_new_env(env);
	else
	{
		PRINT_ERR(MSH_SETENV_INVALID_ARG, env);
	}
}

void			msh_setenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(MSH_SETENV_USG, NULL);
		return ;
	}
	while (*args)
		msh_setenv_one_env(*args++);
}