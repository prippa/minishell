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
#include "messages.h"
#include "builtin.h"

#define MSH_SETENV_USG			"setenv: usage: setenv [key=value] ..."
#define MSH_SETENV_INVALID_ARG	"setenv: '%s' not a valid identifier"

static void		msh_edit_or_set_new_env(const char *env)
{
	t_env	new_env;
	t_env	*edit_env;
	t_list2	*obj;

	new_env.index = ft_strchr(env, KEY_VALUE_SEPARATOR) - env;
	if (!(new_env.env = ft_strdup(env)))
		msh_fatal_err(MALLOC_ERR);
	new_env.env[new_env.index] = 0;
	obj = msh_getenv_obj_by_key(new_env.env);
	new_env.env[new_env.index] = KEY_VALUE_SEPARATOR;
	if (obj)
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

void			msh_setenv_one_env(const char *key, const char *value)
{
	char *env;

	if (!(env = ft_strnew(ft_strlen(key) + ft_strlen(value) + 1)))
		msh_fatal_err(MALLOC_ERR);
	ft_strcpy(env, key);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, value);
	msh_setenv((char*[2]){env, NULL});
	ft_memdel((void **)&env);
}

void			msh_setenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(EXIT_FAILURE, MSH_SETENV_USG, NULL);
		return ;
	}
	while (*args)
	{
		if (msh_setenv_valid(*args))
			msh_edit_or_set_new_env(*args);
		else
		{
			PRINT_ERR(EXIT_FAILURE, MSH_SETENV_INVALID_ARG, *args);
		}
		++args;
	}
}
