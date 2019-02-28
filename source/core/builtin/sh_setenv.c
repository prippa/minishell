/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:56 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"

#define SH_SETENV_USG			"setenv: usage: setenv [key=value] ..."
#define SH_SETENV_INVALID_ARG	"setenv: '%s' not a valid identifier"

static void		sh_edit_or_set_new_env(const char *env)
{
	t_env	new_env;
	t_env	*edit_env;
	t_list2	*obj;

	new_env.index = ft_strchr(env, KEY_VALUE_SEPARATOR) - env;
	if (!(new_env.env = ft_strdup(env)))
		sh_fatal_err(MALLOC_ERR);
	if ((obj = sh_getenv_obj_by_key(env, new_env.index)))
	{
		edit_env = (t_env *)obj->content;
		sh_del_env_body(edit_env);
		ft_memcpy(edit_env, &new_env, sizeof(t_env));
		return ;
	}
	if (!(obj = ft_lst2new(&new_env, sizeof(t_env))))
		sh_fatal_err(MALLOC_ERR);
	ft_lst2_push_back(&g_sh.env_start, &g_sh.env_end, obj);
	++g_sh.env_size;
}

static t_bool	sh_setenv_valid(const char *env)
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

void			sh_setenv_one_env(const char *key, const char *value)
{
	char *env;

	if (!(env = ft_strnew(ft_strlen(key) + ft_strlen(value) + 1)))
		sh_fatal_err(MALLOC_ERR);
	ft_strcpy(env, key);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, value);
	sh_setenv((char*[2]){env, NULL});
	ft_memdel((void **)&env);
}

void			sh_setenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(EXIT_FAILURE, SH_SETENV_USG, NULL);
		return ;
	}
	while (*args)
	{
		if (sh_setenv_valid(*args))
			sh_edit_or_set_new_env(*args);
		else
		{
			PRINT_ERR(EXIT_FAILURE, SH_SETENV_INVALID_ARG, *args);
		}
		++args;
	}
}
