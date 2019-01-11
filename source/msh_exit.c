/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:21 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		msh_error_exit(t_msh *msh, const char *message)
{
	ft_dprintf(2, MSH_ERR, message);
	msh_free(msh);
	system("leaks -q minishell");
	exit(-1);
}

void		msh_exit(t_msh *msh, char **args)
{
	(void)args;
	msh_free(msh);
	system("leaks -q minishell");
	exit(0);
}
