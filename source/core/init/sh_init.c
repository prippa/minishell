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

void		sh_init_termios(void)
{
	struct termios	newtio;

	newtio = sh()->oldtio;
	newtio.c_lflag &= ~(ICANON | ECHO | ECHONL);
	if ((tcsetattr(0, TCSANOW, &newtio)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
}

void		sh_init(void)
{
	char *pwd;

	ft_bzero(sh(), sizeof(t_shell));
	if ((tcgetattr(0, &sh()->oldtio)) == ERR)
		sh_fatal_err(TCGETATTR_FAILED);
	sh()->ok = true;
	GET_MEM(GETCWD_FAILED, pwd, getcwd, NULL, 0);
	sh()->pwd = pwd;
	sh_init_env();
	sh_update_curent_dir_name();
	sh_update_prompt(true);
	signal(SIGINT, sh_handle_sigint_base);
}
