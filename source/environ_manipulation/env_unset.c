/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:54:46 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 13:54:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"

int32_t		env_unset(t_list2 **env_start, t_list2 **env_end, const char *key)
{
	t_list2		*obj;

	if (!(obj = env_get_obj_by_key(*env_start, key)))
		return (ERR);
	ft_lst2del_by_obj(env_start, env_end, obj, env_del_list);
	return (0);
}
