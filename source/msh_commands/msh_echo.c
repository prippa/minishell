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

static void	msh_echo_print(const char *arg, t_bool *mod)
{
	// while (*arg)
	// {
	// 	if (*arg == '\'' || *arg == '\"')
	// 		*mod = SWITCH_LOGIC(*mod);
	// 	if (*mod)
	// 		msh_echo_print_base()
	// 	++arg;
	// }
}

static void	msh_echo_loop(char **args)
{
	t_bool	mod;

	mod = 1;
	while (*args)
	{
		msh_echo_print(*args++, &mod);
		ft_putchar(' ');
	}
}

void		msh_echo(t_msh *msh, char **args)
{
	t_bool	new_line_flag;

	(void)msh;
	new_line_flag = false;
	if (*args)
	{
		if (!ft_strcmp(ECHO_FLAG, *args))
			new_line_flag = true;
		msh_echo_loop(&args[new_line_flag]);
	}
	if (!new_line_flag)
		ft_putchar('\n');
}
