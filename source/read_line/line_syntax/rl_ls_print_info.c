/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:51 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "messages.h"

#define LS_ERR				SHELL_NAME ": syntax error : "
#define WTF_SEMICOLON_X1	LS_ERR "near unexpected token `;'"
#define WTF_SEMICOLON_X2	LS_ERR "near unexpected token `;;'"

#define QUOT_PROMPT			"quote> "
#define DQUOT_PROMPT		"dquote> "
#define SLASH_PROMPT		"> "

void	ls_print_info(int32_t key)
{
	if (key == RL_OK)
		return ;
	if (key == RL_SEMIX1)
	{
		PRINT_ERR(EXIT_FAILURE, WTF_SEMICOLON_X1, NULL);
	}
	else if (key == RL_SEMIX2)
	{
		PRINT_ERR(EXIT_FAILURE, WTF_SEMICOLON_X2, NULL);
	}
	else if (key == RL_Q)
		ft_putstr(QUOT_PROMPT);
	else if (key == RL_DQ)
		ft_putstr(DQUOT_PROMPT);
	else if (key == RL_SLASH)
		ft_putstr(SLASH_PROMPT);
}
