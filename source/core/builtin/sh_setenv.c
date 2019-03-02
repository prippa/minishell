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
#include "environ_manipulation.h"

#define SH_SETENV_USG			"setenv: usage: setenv [key=value] ..."
#define SH_SETENV_INVALID_ARG	"setenv: '%s' not a valid identifier"

static int32_t	sh_setenv_one_env(const char *env)
{
	int32_t	res;
	size_t	len;
	t_env	e;

	if (!(len = ft_strchr(env, KEY_VALUE_SEPARATOR) - env))
		return (ERR);
	if (!(e.key = ft_strsub(env, 0, len)))
		sh_fatal_err(MALLOC_ERR);
	if (!(e.value = ft_strdup(&env[len + 1])))
		sh_fatal_err(MALLOC_ERR);
	res = env_set(&g_sh.env_start, &g_sh.env_end, &e, true);
	// env_del_body(&e);
	return (res);
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
		if (sh_setenv_one_env(*args))
		{
			PRINT_ERR(EXIT_FAILURE, SH_SETENV_INVALID_ARG, *args);
		}
		++args;
	}
}
