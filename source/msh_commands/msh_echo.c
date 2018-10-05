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

static void	msh_echo_print(t_msh *msh, char **args)
{
	t_echo_mode	mode;
	char		*str;

	mode = BASE_MODE;
	while (*args)
	{
		str = *args;
		while (*str)
		{
			ft_putchar(*str++);
		}
		ft_putchar(' ');
		++args;
	}
}

void		msh_echo(t_msh *msh, char **args)
{
	t_bool	new_line_flag;

	new_line_flag = false;
	if (*args)
	{
		if (!ft_strcmp(ECHO_FLAG, *args))
			new_line_flag = true;
		msh_echo_print(msh, &(args)[new_line_flag]);
	}
	if (new_line_flag)
		ft_putchar('\n');
	ft_putchar('\n');
}
