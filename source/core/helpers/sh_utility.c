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
#include "environ_manipulation.h"

#define SH_ERR		"ERROR: " SHELL_NAME " : %s\n"

// char		*sh_join_to_pwd(const char *name)
// {
// 	char	*pwd;

// 	GET_MEM(GETCWD_FAILED, pwd, getcwd, NULL, 0);
// 	GET_MEM(MALLOC_ERR, pwd, ft_strjoin_free,
// 		&pwd, (char[2]){ UNIX_PATH_SEPARATOR, 0 }, ft_strlen(pwd), 1);
// 	GET_MEM(MALLOC_ERR, pwd, ft_strjoin_free,
// 		&pwd, name, ft_strlen(pwd), ft_strlen(name));
// 	return (pwd);
// }

t_shell		*sh(void)
{
	static t_shell sh;

	return (&sh);
}

void		sh_update_curent_dir_name(void)
{
	char	*home;
	char	*file;
	char	*pwd;

	GET_MEM(GETCWD_FAILED, pwd, getcwd, NULL, 0);
	if (((home = env_get_vlu_by_key(sh()->env_start, HOME_ENV)) &&
		!ft_strcmp(home, pwd)))
		ft_strcpy(sh()->curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(sh()->curent_path, file);
	}
	else
		ft_strcpy(sh()->curent_path, pwd);
	ft_memdel((void **)&pwd);
}

void		sh_fatal_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, SH_ERR, message);
	exit(EXIT_FAILURE);
}
