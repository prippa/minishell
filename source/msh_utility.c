/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 18:10:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

#define STAT_FAILED	"stat failed"

t_bool		msh_is_dir(t_minishel *msh, const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		msh_error_exit(msh, STAT_FAILED);
	return (S_ISDIR(sb.st_mode));
}

t_bool		msh_is_valid_path(const char *path)
{
	uint16_t	i;

	i = 0;
	while (*path)
	{
		if (*path == UNIX_PATH_SEPARATOR)
			i = 0;
		else if (++i > FILENAME_MAX)
			return (false);
		++path;
	}
	return (true);
}

void		msh_print_error(t_minishel *msh, const char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	msh->success_exec = false;
}
