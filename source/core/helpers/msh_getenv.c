/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:42:12 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:42:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list2		*msh_getenv_obj_by_key(const char *key)
{
	t_env	*e;
	t_list2	*start;
	size_t	len;

	start = g_msh.env_start;
	len = ft_strlen(key);
	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, key, len))
			return (start);
		start = start->next;
	}
	return (NULL);
}

char		*msh_getenv_vlu_by_key(const char *key)
{
	t_env	*e;
	t_list2	*start;
	size_t	len;

	start = g_msh.env_start;
	len = ft_strlen(key);
	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, key, len))
			return (e->env + len + 1);
		start = start->next;
	}
	return (NULL);
}
