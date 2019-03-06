/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:38 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "read_line.h"

void		sh_handle_sigint_rl(int sig)
{
	if (sig == SIGINT)
	{
		ft_memdel((void **)&rl()->line);
		sh()->exec_code = SIGINT;
		ft_putchar_fd('\n', STDERR_FILENO);
		sh_update_prompt(false);
		ft_putstr(sh()->prompt);
	}
}

void		sh_handle_sigint_base(int sig)
{
	if (sig == SIGINT)
	{
		sh()->exec_code = SIGINT;
		ft_putchar_fd('\n', STDERR_FILENO);
		sh_update_prompt(false);
		ft_putstr(sh()->prompt);
	}
}

void		sh_handle_sigint_incase(int sig)
{
	if (sig == SIGINT)
	{
		PRINT_ERR(SIGINT, EMPTY_STR, NULL);
	}
}
