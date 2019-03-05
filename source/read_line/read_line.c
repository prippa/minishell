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

#define RL_BUFF_SIZE 2

t_read_line		*rl(void)
{
	static t_read_line rl;

	return (&rl);
}

static void	read_line_loop(void)
{
	ssize_t		ret;
	int32_t		rl_ls_res;
	char		buf[RL_BUFF_SIZE];

	ft_bzero(&buf, RL_BUFF_SIZE);
	while ((ret = read(STDIN_FILENO, buf, 1)) > 0)
	{
		rl()->new_line_flag = true;
		if (!rl()->line && !(rl()->line = ft_strdup("")))
			sh_fatal_err(MALLOC_ERR);
		if (buf[0] == '\n')
		{
			if (!(rl_ls_res = rl_line_syntax()))
				break ;
			ls_print_info(rl_ls_res);
			if (rl_ls_res < 0)
				break ;
		}
		if (rl()->new_line_flag &&
			!(ft_strjoin_free(&rl()->line, buf, ft_strlen(rl()->line), 1)))
				sh_fatal_err(MALLOC_ERR);
	}
	if (ret == -1)
		sh_fatal_err(READ_ERR);
}

char			*read_line(void)
{
	ft_bzero(rl(), sizeof(t_read_line));
	ft_putstr(sh()->prompt);
	signal(SIGINT, sh_handle_sigint_rl);
	read_line_loop();
	signal(SIGINT, sh_handle_sigint_base);
	if (rl()->line)
		ls_check_for_unexpected_eof(rl_line_syntax());
	return (rl()->line);
}
