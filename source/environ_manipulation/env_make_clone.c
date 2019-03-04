/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_make_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:28:01 by prippa            #+#    #+#             */
/*   Updated: 2019/03/03 14:28:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "shell.h"

t_env		env_make_clone_of_body(const t_env *origin)
{
	t_env	cpy;

	GET_MEM(MALLOC_ERR, cpy.key, ft_strdup, origin->key);
	GET_MEM(MALLOC_ERR, cpy.value, ft_strdup, origin->value);
	return (cpy);
}

void		env_make_clone(t_list2 **dst_start, t_list2 **dst_end,
				t_list2 *src_start)
{
	t_list2 *new_obj;
	t_env	e;

	while (src_start)
	{
		e = env_make_clone_of_body(src_start->content);
		GET_MEM(MALLOC_ERR, new_obj, ft_lst2new, &e, sizeof(t_env));
		ft_lst2_push_back(dst_start, dst_end, new_obj);
		src_start = src_start->next;
	}
}
