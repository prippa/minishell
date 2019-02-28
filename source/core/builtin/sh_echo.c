/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:46 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define ECHO_NEW_LINE_F	"-n"

static void	sh_echo_flags(t_bool *f, char ***args)
{
	while (**args)
	{
		if (!ft_strcmp(**args, ECHO_NEW_LINE_F))
			*f = true;
		else
			break ;
		++(*args);
	}
}

void		sh_echo(char **args)
{
	t_bool nl_f;

	nl_f = false;
	sh_echo_flags(&nl_f, &args);
	while (*args)
	{
		ft_putstr(*args++);
		if (*args)
			ft_putchar(' ');
	}
	if (!nl_f)
		ft_putchar('\n');
}
