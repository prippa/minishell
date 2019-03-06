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
#include "messages.h"

void		sh_init(void)
{
	char *pwd;

	ft_bzero(sh(), sizeof(t_shell));
	sh()->ok = true;
	GET_MEM(GETCWD_FAILED, pwd, getcwd, NULL, 0);
	sh()->pwd = pwd;
	sh_init_env();
	sh_update_curent_dir_name();
	sh_update_prompt(true);
	signal(SIGINT, sh_handle_sigint_base);
}
