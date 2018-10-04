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
	t_list2 *start;

	start = msh->env_start;
	while (start)
	{
		if (!ft_strcmp(((t_env *)start->content)->name, "PWD"))
			ft_strcpy(msh->curent_dir_path,
				ft_strrchr(((t_env *)start->content)->arg, '/') + 1);
		start = start->next;
	}
}
