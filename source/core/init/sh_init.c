/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <signal.h>

t_bool	g_ok;
int32_t	g_exec_code;
t_shell	g_sh;

void		sh_init(void)
{
	ft_bzero(&g_sh, sizeof(t_shell));
	sh_init_env();
	g_ok = true;
	g_exec_code = EXIT_SUCCESS;
	sh_update_curent_dir_name();
	sh_update_prompt();
}
