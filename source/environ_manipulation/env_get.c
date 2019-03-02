/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:42:12 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:42:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"

t_list2		*env_get_obj_by_key(t_list2 *env_start, const char *key)
{
	while (env_start)
	{
		if (!ft_strcmp(((t_env *)env_start->content)->key, key))
			return (env_start);
		env_start = env_start->next;
	}
	return (NULL);
}

char		*env_get_vlu_by_key(t_list2 *env_start, const char *key)
{
	t_env *e;

	while (env_start)
	{
		e = (t_env *)env_start->content;
		if (!ft_strcmp(e->key, key))
			return (e->value);
		env_start = env_start->next;
	}
	return (NULL);
}
