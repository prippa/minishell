/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:42:12 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:42:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list2		*msh_env_get_obj_by_key(t_list2 *start, const char *env, size_t len)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, env, len))
			return (start);
		start = start->next;
	}
	return (NULL);
}

const char	*msh_env_get_value_by_key(t_list2 *start, const char *env, size_t len)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, env, e->index))
			return (e->env + e->index + 1);
		start = start->next;
	}
	return (NULL);
}
