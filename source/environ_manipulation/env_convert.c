/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:41:57 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 16:41:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "environ_manipulation.h"
#include "messages.h"

static char	*env_convert_to_str(const char *key, const char *value)
{
	char *env;

	if (!(env = ft_strnew(ft_strlen(key) + ft_strlen(value) + 1)))
		sh_fatal_err(MALLOC_ERR);
	ft_strcpy(env, key);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, value);
	return (env);
}

char		**env_convert_to_arr(t_list2 *env_start)
{
	t_env	*e;
	char	**arr;
	size_t	i;

	if (!(arr = (char **)ft_memalloc(sizeof(char *) *
		(ft_lstsize((t_list *)env_start) + 1))))
		sh_fatal_err(MALLOC_ERR);
	i = -1;
	while (env_start)
	{
		e = (t_env *)env_start->content;
		arr[++i] = env_convert_to_str(e->key, e->value);
		env_start = env_start->next;
	}
	return (arr);
}
