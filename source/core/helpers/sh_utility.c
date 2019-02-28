/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 18:10:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "syntax_characters.h"
#include <sys/stat.h>

#define SH_ERR		"ERROR: " SHELL_NAME " : %s\n"

t_bool		sh_is_dir(const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		sh_fatal_err(STAT_FAILED);
	return (S_ISDIR(sb.st_mode));
}

t_bool		sh_is_valid_path(const char *path)
{
	uint16_t	i;

	i = 0;
	while (*path)
	{
		if (*path == UNIX_PATH_SEPARATOR)
			i = 0;
		else if (++i > FILE_NAME_MAX)
			return (true);
		++path;
	}
	return (false);
}

void		sh_update_curent_dir_name(void)
{
	char	*home;
	char	*file;
	char	*pwd;

	if (!(pwd = getcwd(NULL, 0)))
		sh_fatal_err(GETCWD_FAILED);
	if (((home = sh_getenv_vlu_by_key(HOME_ENV, ft_strlen(HOME_ENV))) &&
		!ft_strcmp(home, pwd)))
		ft_strcpy(g_sh.curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(g_sh.curent_path, file);
	}
	else
		ft_strcpy(g_sh.curent_path, pwd);
	ft_memdel((void **)&pwd);
}

void		sh_fatal_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, SH_ERR, message);
	exit(EXIT_FAILURE);
}