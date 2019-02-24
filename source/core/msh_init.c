/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		g_ok;
t_minishel	g_msh;

static void	msh_init_env(void)
{
	extern char	**environ;

	if (*environ)
		msh_setenv(environ);
	
}

void		msh_init(void)
{
	ft_bzero(&g_msh, sizeof(t_minishel));
	msh_init_env();
	g_ok = true;
	msh_update_curent_dir_name();
	msh_update_prompt();
}
