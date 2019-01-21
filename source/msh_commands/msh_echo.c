/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:46 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ECHO_NEW_LINE_F	"-n"

typedef struct	s_echo_flags
{
	t_bool		new_line;
}				t_echo_flags;

static void	msh_echo_flags(t_echo_flags *f, char ***args)
{
	while (**args)
	{
		if (!ft_strcmp(**args, ECHO_NEW_LINE_F))
			f->new_line = true;
		else
			break ;
		++(*args);
	}
}

void		msh_echo(t_minishel *msh, char **args)
{
	t_echo_flags f;

	(void)msh;
	ft_bzero(&f, sizeof(t_echo_flags));
	msh_echo_flags(&f, &args);
	while (*args)
	{
		ft_putstr(*args++);
		if (*args)
			ft_putchar(' ');
	}
	if (!f.new_line)
		ft_putchar('\n');
}
