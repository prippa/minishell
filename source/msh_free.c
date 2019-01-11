/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:26 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		msh_del_env_body(t_env *e)
{
	ft_strdel(&e->value);
}

void		msh_del_env_list(void *content, size_t content_size)
{
	t_env *e;

	e = (t_env *)content;
	(void)content_size;
	msh_del_env_body(e);
	free(content);
}

void		msh_free(t_msh *msh)
{
	ft_lst2del(&msh->env_start, &msh->env_end, msh_del_env_list);
	ft_strdel(&msh->line);
}
