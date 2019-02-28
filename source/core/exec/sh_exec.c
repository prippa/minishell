/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:52:50 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:52:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include <sys/wait.h>

static void		sh_do_magic(const char *path, char **args, char **env)
{
	pid_t	father;

	if ((father = fork()) == ERR)
		sh_fatal_err(FORK_FAILED);
	if (father)
	{
		if (wait(&g_exec_code) == ERR)
			sh_fatal_err(WAIT_FAILED);
		if (WIFEXITED(g_exec_code) && g_exec_code)
		{
			g_exec_code = WEXITSTATUS(g_exec_code);
			g_ok = false;
		}
	}
	if (!father)
	{
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
}

static char		**sh_env_convert_from_list_char(void)
{
	char		**env;
	t_list2		*env_start;
	uint32_t	i;

	if (!(env = (char **)ft_memalloc(sizeof(char *) * (g_sh.env_size + 1))))
		sh_fatal_err(MALLOC_ERR);
	env_start = g_sh.env_start;
	i = -1;
	while (env_start)
	{
		env[++i] = ((t_env *)env_start->content)->env;
		env_start = env_start->next;
	}
	return (env);
}

void			sh_exec(const char *path, char **args)
{
	char		**env;

	if (access(path, X_OK) == ERR)
	{
		PRINT_ERR(EXIT_FAILURE, SH_PERM_DENIED, path);
		return ;
	}
	env = sh_env_convert_from_list_char();
	sh_do_magic(path, args, env);
	free(env);
}
