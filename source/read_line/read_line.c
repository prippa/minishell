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

char			*read_line(const char *prompt)
{
	t_read_line	rl;
	ssize_t		ret;
	char		buf[2];

	ft_bzero(&buf, 2);
	ft_bzero(&rl, sizeof(t_read_line));
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	while ((ret = read(STDIN_FILENO, buf, 1)) > 0)
	{
		rl.new_line_flag = true;
		if (!rl.line && !(rl.line = ft_strdup("")))
			msh_fatal_err(MALLOC_ERR);
		if (buf[0] == '\n' && !rl_line_syntax(&rl))
			break ;
		else if (rl.new_line_flag &&
			!(ft_strjoin_free(&rl.line, buf, ft_strlen(rl.line), 1)))
			msh_fatal_err(MALLOC_ERR);
	}
	if (ret == -1)
		msh_fatal_err(READ_ERR);
	return (rl.line);
}
