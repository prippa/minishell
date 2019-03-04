/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:54:26 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 13:54:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "shell.h"

static void		env_edit(t_list2 *obj, t_env *env)
{
	t_env	*edit_env;

	edit_env = (t_env *)obj->content;
	env_del_body(edit_env);
	ft_memcpy(edit_env, env, sizeof(t_env));
}

void			env_set(t_list2 **env_start, t_list2 **env_end,
					const t_env *new_env, t_bool overwrite)
{
	t_list2	*obj;
	t_env	new_env_cpy;

	new_env_cpy = env_make_clone_of_body(new_env);
	if ((obj = env_get_obj_by_key(*env_start, new_env_cpy.key)))
	{
		if (overwrite)
			env_edit(obj, &new_env_cpy);
		return ;
	}
	GET_MEM(MALLOC_ERR, obj, ft_lst2new, &new_env_cpy, sizeof(t_env));
	ft_lst2_push_back(env_start, env_end, obj);
}
