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
	ft_putendl(((t_env *)elem->content)->value);
}

void		msh_env(t_msh *msh, char **args)
{
	(void)args;
	ft_lst2iter(msh->env_start, msh_print_env_elem);
}
