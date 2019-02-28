/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:42:12 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:42:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list2		*sh_getenv_obj_by_key(const char *key, size_t len)
{
	t_env	*e;
	t_list2	*start;

	start = g_sh.env_start;
	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, key, len))
			return (start);
		start = start->next;
	}
	return (NULL);
}

char		*sh_getenv_vlu_by_key(const char *key, size_t len)
{
	t_env	*e;
	t_list2	*start;

	start = g_sh.env_start;
	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->env, key, len))
			return (e->env + len + 1);
		start = start->next;
	}
	return (NULL);
}
