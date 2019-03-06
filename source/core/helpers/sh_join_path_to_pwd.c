/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_join_path_to_pwd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:48:57 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 15:48:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"

static void	sh_move(char **pwd, const char *dir)
{
	size_t	len;
	int32_t	root_dir;

	if (!ft_strcmp(dir, CUR_DIR) || !ft_strcmp(dir, EMPTY_STR))
		return ;
	root_dir = ft_strequ(*pwd, (char[2]){UNIX_PATH_SEPARATOR, 0});
	if (!ft_strcmp(dir, PREV_DIR))
	{
		if (!root_dir)
		{
			if (!(len = ft_strrchr(*pwd, UNIX_PATH_SEPARATOR) - *pwd))
				++len;
			GET_MEM(MALLOC_ERR, *pwd, ft_strsub_free, pwd, 0, len);
		}
	}
	else
	{
		if (!root_dir)
			GET_MEM(MALLOC_ERR, *pwd, ft_strjoin_free,
			pwd, (char[2]){UNIX_PATH_SEPARATOR, 0}, ft_strlen(*pwd), 1);
		GET_MEM(MALLOC_ERR, *pwd, ft_strjoin_free,
			pwd, dir, ft_strlen(*pwd), ft_strlen(dir));
	}
}

char		*sh_join_path_to_pwd(const char *cur_pwd, const char *path)
{
	char	*pwd;
	char	*dir;
	size_t	len;

	if (*path != UNIX_PATH_SEPARATOR)
	{
		GET_MEM(MALLOC_ERR, pwd, ft_strdup, cur_pwd);
	}
	else
		GET_MEM(MALLOC_ERR, pwd, ft_strdup, (char[2]){UNIX_PATH_SEPARATOR, 0});
	len = 0;
	while (true)
	{
		if (*path == UNIX_PATH_SEPARATOR || !*path)
		{
			GET_MEM(MALLOC_ERR, dir, ft_strsub, path - len, 0, len);
			sh_move(&pwd, dir);
			ft_memdel((void **)&dir);
			len = -1;
		}
		if (!*path++)
			break ;
		++len;
	}
	return (pwd);
}
