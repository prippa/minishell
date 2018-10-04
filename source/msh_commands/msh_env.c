/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:51 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_print_env_elem(t_list2 *elem)
{
	t_env *e;

	e = (t_env *)elem->content;
	ft_printf("%s=%s\n", e->name, e->arg);
}

void		msh_env(t_msh *msh)
{
	ft_lst2iter(msh->env_start, msh_print_env_elem);
}
