#include "minishell.h"
#include <sys/wait.h>
#include <signal.h>

#define EXEC_IS_FOLDER		"%s: Is a directory\n"
#define	EXEC_PERM_DENIED	"%s: Permission denied\n"
#define	FORK_FAILED			"fork failed"
#define	WAIT_FAILED			"wait failed"
#define	EXECVE_FAILED		"execve failed"

static void		msh_do_magic(const char *path, char **args, char **env)
{
	int32_t	wstatus;
	pid_t	father;

	if ((father = fork()) == ERR)
		msh_fatal_err(FORK_FAILED);
	if (father)
	{
		if (wait(&wstatus) == ERR)
			msh_fatal_err(WAIT_FAILED);
		if (wstatus)
			g_ok = false;
	}
	if (!father)
	{
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
}

static char		**msh_env_convert_from_list_char(void)
{
	char		**env;
	t_list2		*env_start;
	uint32_t	i;

	if (!(env = (char **)malloc(sizeof(char *) * (g_msh.env_size + 1))))
		msh_fatal_err(MALLOC_ERR);
	env[g_msh.env_size] = NULL;
	env_start = g_msh.env_start;
	i = -1;
	while (env_start)
	{
		env[++i] = ((t_env *)env_start->content)->env;
		env_start = env_start->next;
	}
	return (env);
}

static t_bool	msh_fork_exec_vild_path(const char *path)
{
	if (msh_is_dir(path))
		ft_dprintf(STDERR_FILENO, EXEC_IS_FOLDER, path);
	else if (access(path, X_OK) == ERR)
		ft_dprintf(STDERR_FILENO, EXEC_PERM_DENIED, path);
	else
		return (true);
	return (false);
}

void			msh_exec(const char *path, char **args)
{
	char		**env;

	if (!(g_ok = msh_fork_exec_vild_path(path)))
		return ;
	env = msh_env_convert_from_list_char();
	msh_do_magic(path, args, env);
	free(env);
}
