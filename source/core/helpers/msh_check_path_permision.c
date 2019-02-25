/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_check_path_permision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:32:09 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 12:32:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "messages.h"

static t_bool	msh_path_access_check(char *s, size_t i,
					const char *path, const char *prefix)
{
	t_bool	res;

	res = true;
	s[i] = 0;
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(EXIT_FAILURE, NO_FILE_OR_DIR, path);
	}
	else if (access(s, X_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(EXIT_FAILURE, PERM_DENIED, path);
	}
	else
		res = false;
	s[i] = UNIX_PATH_SEPARATOR;
	return (res);
}

static t_bool	msh_path_access_loop(char *s, const char *path,
					const char *prefix)
{
	size_t	i;

	i = -1;
	if (*s == UNIX_PATH_SEPARATOR)
		++i;
	while (s[++i])
		if (s[i] == UNIX_PATH_SEPARATOR &&
			msh_path_access_check(s, i, path, prefix))
			return (true);
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(EXIT_FAILURE, NO_FILE_OR_DIR, s);
		return (true);
	}
	return (false);
}

t_bool			msh_path_access(const char *path, const char *prefix)
{
	char	*s;
	t_bool	res;

	if (!(s = ft_strdup(path)))
		msh_fatal_err(MALLOC_ERR);
	res = msh_path_access_loop(s, path, prefix);
	ft_memdel((void **)&s);
	return (res);
}
