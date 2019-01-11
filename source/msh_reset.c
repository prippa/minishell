/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:50 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		msh_update_curent_dir_name(t_msh *msh)
{
	char *path;
	char *dir;

	if ((path = msh_env_get_arg_by_name(msh->env_start, "PWD")))
	{
		if ((dir = ft_strrchr(path, '/')))
			++dir;
		else
			dir = path;
		ft_strcpy(msh->curent_dir, dir);
	}
}
