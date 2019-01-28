#include "minishell.h"
#include <sys/wait.h>

#define EXEC_IS_FOLDER		"%s: Is a directory\n"
#define	EXEC_PERM_DENIED	"%s: Permission denied\n"
#define	FORK_FAILED			"fork failed"
#define	WAIT_FAILED			"wait failed"
#define	EXECVE_FAILED		"execve failed"

static void		msh_do_magic(t_minishel *msh,
					const char *path, char **args, char **env)
{
	pid_t	father;
	int		wstatus;

	if ((father = fork()) == ERR)
		msh_error_exit(msh, FORK_FAILED);
	if (father)
	{
		if (wait(&wstatus) == ERR)
			msh_error_exit(msh, WAIT_FAILED);
		if (wstatus)
			msh->success_exec = false;
	}
	if (!father)
	{
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
}

static char		**msh_env_convert_from_list_char(t_minishel *msh)
{
	char		**env;
	t_list2		*env_start;
	uint32_t	i;

	if (!(env = (char **)malloc(sizeof(char *) * (msh->env_size + 1))))
		msh_error_exit(msh, MALLOC_ERR);
	env[msh->env_size] = NULL;
	env_start = msh->env_start;
	i = -1;
	while (env_start)
	{
		env[++i] = ((t_env *)env_start->content)->env;
		env_start = env_start->next;
	}
	return (env);
}

static t_bool	msh_fork_exec_vild_path(t_minishel *msh,
					const char *path)
{
	if (msh_is_dir(msh, path))
		ft_dprintf(STDERR_FILENO, EXEC_IS_FOLDER, path);
	else if (access(path, X_OK) == ERR)
		ft_dprintf(STDERR_FILENO, EXEC_PERM_DENIED, path);
	else
		return (true);
	return (false);
}

void			msh_fork_exec(t_minishel *msh,
					const char *path, char **args)
{
	char		**env;

	if (!(msh->success_exec = msh_fork_exec_vild_path(msh, path)))
		return ;
	env = msh_env_convert_from_list_char(msh);
	msh_do_magic(msh, path, args, env);
	free(env);
}
