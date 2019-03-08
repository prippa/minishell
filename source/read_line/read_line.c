/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:16:17 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:16:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "messages.h"

#define RL_BUFF_SIZE 8

t_read_line		*rl(void)
{
	static t_read_line rl;

	return (&rl);
}

static int32_t	rl_key_events(char buf[RL_BUFF_SIZE])
{
	if ((UP) || (DOWN) || (LEFT) || (RIGHT) || (WTF_UP) || (WTF_DOWN) ||
	(BACK_SPACE) || (TAB) || (CTRL_D) || (NEW_LINE))
	{
		if (BACK_SPACE)
			rl_back_space();
		else if (TAB)
			rl_tab();
		else if (CTRL_D)
			rl_ctrl_d();
		else if (NEW_LINE)
			return (rl_new_line());
		return (RL_CONTINUE);
	}
	return (RL_OK);
}

static void		read_line_loop(void)
{
	int32_t		ke_res;
	char		buf[RL_BUFF_SIZE + 1];

	while (true)
	{
		rl()->new_line_flag = true;
		ft_bzero(buf, RL_BUFF_SIZE + 1);
		if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
			sh_fatal_err(READ_ERR);
		if (!rl()->line && !(rl()->line = ft_strdup("")))
			sh_fatal_err(MALLOC_ERR);
		if ((ke_res = rl_key_events(buf)) == RL_BREAK)
			break ;
		else if (ke_res == RL_CONTINUE)
			continue ;
		rl_join_str_to_line(buf);
		ft_putstr(buf);
	}
}

char			*read_line(void)
{
	ft_bzero(rl(), sizeof(t_read_line));
	ft_putstr(sh()->prompt);
	signal(SIGINT, sh_handle_sigint_rl);
	sh_init_termios();
	read_line_loop();
	if ((tcsetattr(0, TCSANOW, &sh()->oldtio)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	signal(SIGINT, sh_handle_sigint_base);
	return (rl()->line);
}
