/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:51 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	sh_print_env_elem(t_list2 *elem)
{
	ft_putendl(((t_env *)elem->content)->env);
}

void		sh_env(char **args)
{
	(void)args;
	ft_lst2iter(g_sh.env_start, sh_print_env_elem);
}
