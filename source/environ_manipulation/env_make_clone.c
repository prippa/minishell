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

// int32_t		env_make_clone()
