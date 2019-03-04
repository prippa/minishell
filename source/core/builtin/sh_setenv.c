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

#define SH_SETENV_INVALID_ARG	"setenv: '%s' not a valid identifier"

static int32_t	sh_setenv_one_env(t_build *b)
{
	char	*i;
	int32_t	res;
	t_env	e;

	if (!(i = ft_strchr(*b->args, KEY_VALUE_SEPARATOR)))
		return (ERR);
	GET_MEM(MALLOC_ERR, e.key, ft_strsub, *b->args, 0, i - *b->args);
	GET_MEM(MALLOC_ERR, e.value, ft_strdup, &(*b->args)[(i - *b->args) + 1]);
	res = env_set(b->env_start, b->env_end, &e, true);
	env_del_body(&e);
	return (res);
}

void			sh_setenv(t_build *b)
{
	if (!*b->args)
	{
		env_print(*b->env_start);
		return ;
	}
	while (*b->args)
	{
		if (sh_setenv_one_env(b))
		{
			PRINT_ERR(EXIT_FAILURE, SH_SETENV_INVALID_ARG, *b->args);
		}
		++b->args;
	}
}
