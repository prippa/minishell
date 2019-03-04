/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:21 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"

#define EXIT_NAR	SHELL_NAME ": " EXIT_CMD ": %s: numeric argument required"
#define EXIT_TMA	SHELL_NAME ": " EXIT_CMD ": " TO_MANY_ARGS
#define EXIT_MSG	"exit"

static int32_t	sh_exit_get_arg_value(char **args)
{
	if (*(args + 1))
	{
		PRINT_ERR(EXIT_FAILURE, EXIT_TMA, NULL);
		return (ERR);
	}
	if (!ft_is_str_digit(*args))
	{
		PRINT_ERR(EXIT_FAILURE, EXIT_NAR, *args);
		return (EXIT_FAILURE);
	}
	return (ft_atoi(*args));
}

void			sh_exit(t_build *b)
{
	int32_t exit_code;

	if (b && *b->args)
	{
		if ((exit_code = sh_exit_get_arg_value(b->args)) == ERR)
			return ;
	}
	else
		exit_code = g_exec_code;
	ft_putendl(EXIT_MSG);
	exit(exit_code);
}
