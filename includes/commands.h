#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

# define MSH_CMD_SIZE	6

static const char	*g_cmd_string[MSH_CMD_SIZE] =
{
	"cd", "echo", "env", "setenv",
	"unsetenv", "exit"
};

typedef void		(*t_func_cmd)(t_msh *msh, char **args);
static const		t_func_cmd	g_cmd_func[MSH_CMD_SIZE] =
{
	msh_cd, msh_echo, msh_env, msh_setenv,
	msh_unsetenv, msh_exit
};

#endif
