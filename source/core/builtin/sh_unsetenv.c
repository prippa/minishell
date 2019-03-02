/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:02 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "environ_manipulation.h"

#define SH_UNSETENV_USG		"unsetenv: usage: unsetenv [key] ..."
#define SH_UNSETENV_NO_NAME	"unsetenv: '%s' not found"

void	sh_unsetenv(char **args)
{
	if (!*args)
	{
		PRINT_ERR(EXIT_FAILURE, SH_UNSETENV_USG, NULL);
		return ;
	}
	while (*args)
	{
		if (env_unset(&g_sh.env_start, &g_sh.env_end, *args))
		{
			PRINT_ERR(EXIT_FAILURE, SH_UNSETENV_NO_NAME, *args);
		}
		++args;
	}
}
