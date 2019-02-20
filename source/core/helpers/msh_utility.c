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
#include "syntax_characters.h"

#define MSH_ERR			"ERROR: minishell : %s\n"
#define STAT_FAILED		"stat failed\n"
#define GETCWD_FAILED	"getcwd failed\n"

t_bool		msh_is_dir(const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		msh_fatal_err(STAT_FAILED);
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
		else if (++i > FILE_NAME_MAX)
			return (false);
		++path;
	}
	return (true);
}

void		msh_update_curent_dir_name(void)
{
	const char	*home;
	char		*file;
	char		*pwd;

	if (!(pwd = getcwd(NULL, 0)))
		msh_fatal_err(GETCWD_FAILED);
	if ((home = msh_getenv_value_by_key(g_msh.env_start,
		HOME_ENV, ft_strlen(HOME_ENV))) && !ft_strcmp(home, pwd))
		ft_strcpy(g_msh.curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(g_msh.curent_path, file);
	}
	else
		ft_strcpy(g_msh.curent_path, pwd);
	ft_memdel((void **)&pwd);
}

void		msh_fatal_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, MSH_ERR, message);
	exit(EXIT_FAILURE);
}
