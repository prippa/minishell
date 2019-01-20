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
#include "ft_printf.h"

#define MSH_ERR	"ERROR: minishell : %s\n"

void		msh_error_exit(t_minishel *msh, const char *message)
{
	ft_dprintf(STDERR_FILENO, MSH_ERR, message);
	msh_free(msh);
	system("leaks -q minishell");
	exit(EXIT_FAILURE);
}

void		msh_error_exit_no_message(t_minishel *msh)
{
	msh_free(msh);
	system("leaks -q minishell");
	exit(EXIT_FAILURE);
}

void		msh_exit(t_minishel *msh, char **args)
{
	(void)args;
	msh_free(msh);
	system("leaks -q minishell");
	exit(EXIT_SUCCESS);
}
