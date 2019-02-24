#include "minishell.h"
#include "messages.h"

static void	msh_set_shell_lvl(void)
{
	char		*value;

	if ((value = msh_getenv_vlu_by_key(SHELL_LVL_ENV)))
	{
		if (!(value = ft_itoa_max(ft_atoi_max(value) + 1)))
			msh_fatal_err(MALLOC_ERR);
		msh_setenv_one_env(SHELL_LVL_ENV, value);
		ft_memdel((void **)&value);
	}
	else
		msh_setenv_one_env(SHELL_LVL_ENV, "1");
}

static void	msh_set_pwd(void)
{
	char *value;

	if (!(value = msh_getenv_vlu_by_key(PWD_ENV)))
	{
		if (!(value = getcwd(NULL, 0)))
			msh_fatal_err(GETCWD_FAILED);
		msh_setenv_one_env(PWD_ENV, value);
	}
}

void		msh_init_env(void)
{
	extern char	**environ;

	if (*environ)
		msh_setenv(environ);
	msh_setenv_one_env(SHELL_ENV, SHELL_NAME);
	msh_set_pwd();
	msh_set_shell_lvl();
}
