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

static void		env_edit_or_set(t_list2 **env_start, t_list2 **env_end,
					const t_env *new_env, t_bool overwrite)
{
	t_list2	*obj;
	t_env	*edit_env;
	if ((obj = env_get_obj_by_key(*env_start, new_env->key)))
	{
		if (overwrite)
		{
			edit_env = (t_env *)obj->content;
			env_del_body(edit_env);
			ft_memcpy(edit_env, new_env, sizeof(t_env));
		}
		return ;
	}
	if (!(obj = ft_lst2new(new_env, sizeof(t_env))))
		sh_fatal_err(MALLOC_ERR);
	ft_lst2_push_back(env_start, env_end, obj);
}

static t_bool	env_set_valid(const char *key)
{
	if (ft_isalpha_in_case(*key))
	{
		while (*(++key))
			if (!ft_isalnum_in_case(*key))
				return (false);
		return (true);
	}
	return (false);
}

int32_t			env_set(t_list2 **env_start, t_list2 **env_end,
					const t_env *new_env, t_bool overwrite)
{
	if (!env_set_valid(new_env->key))
		return (ERR);
	env_edit_or_set(env_start, env_end, new_env, overwrite);
	return (0);
}
