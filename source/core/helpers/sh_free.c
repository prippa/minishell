/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:26 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		sh_del_env_body(t_env *e)
{
	ft_memdel((void **)&e->env);
}

void		sh_del_env_list(void *content, size_t content_size)
{
	t_env *e;

	e = (t_env *)content;
	(void)content_size;
	sh_del_env_body(e);
	free(content);
}
