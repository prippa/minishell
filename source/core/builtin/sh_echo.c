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

#include "libft.h"
#include "builtin.h"

#define ECHO_NEW_LINE_F	"-n"

static void	sh_echo_flags(t_bool *f, char ***args)
{
	while (**args)
	{
		if (!ft_strcmp(**args, "-n"))
			*f = true;
		else
			break ;
		++(*args);
	}
}

void		sh_echo(t_build *b)
{
	t_bool nl_f;

	nl_f = false;
	sh_echo_flags(&nl_f, &b->args);
	while (*b->args)
	{
		ft_putstr(*b->args++);
		if (*b->args)
			ft_putchar(' ');
	}
	if (!nl_f)
		ft_putchar('\n');
}
