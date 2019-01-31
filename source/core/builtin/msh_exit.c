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

#define EXIT_MSG	"exit"

void		msh_exit(char **args)
{
	(void)args;
	ft_putendl(EXIT_MSG);
	exit(EXIT_SUCCESS);
}
