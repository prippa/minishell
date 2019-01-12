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

t_list2	*msh_env_get_obj_by_name(t_list2 *start, const char *value, size_t len)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->value, value, len))
			return (start);
		start = start->next;
	}
	return (NULL);
}

char	*msh_env_get_arg_by_name(t_list2 *start, const char *value, size_t len)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (e->index == len && !ft_strncmp(e->value, value, e->index))
			return (e->value + e->index + 1);
		start = start->next;
	}
	return (NULL);
}
