#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "messages.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT_SIZE	512
# define MSH_CMD_SIZE	6

typedef struct		s_cmd
{
	char			**args;
}					t_cmd;

typedef struct		s_env
{
	char			*name;
	char			*arg;
}					t_env;

typedef struct		s_msh
{
	char			prompt[PROMPT_SIZE];
	char			curent_dir_path[PATH_MAX + 1];
	t_list2			*env_start;
	t_list2			*env_end;
	t_list2			*cmd_start;
	t_list2			*cmd_end;
	char			*line;
}					t_msh;

void				msh_free(t_msh *msh);
void				msh_error_exit(t_msh *msh, const char *message);
void				msh_exit(t_msh *msh);
void				msh_update_curent_dir_name(t_msh *msh);
void				msh_parse_line(t_msh *msh);
void				msh_del_cmd_list(void *content, size_t content_size);
void				msh_execute_cmds(t_msh *msh);

void				msh_cd(t_msh *msh);
void				msh_echo(t_msh *msh);
void				msh_env(t_msh *msh);
void				msh_setenv(t_msh *msh);
void				msh_unsetenv(t_msh *msh);

static const char	*g_cmd_string[MSH_CMD_SIZE] =
{
	"cd", "echo", "env", "setenv",
	"unsetenv", "exit"
};

typedef void		(*t_func_cmd)(t_msh *msh);
static const 		t_func_cmd	g_cmd_func[MSH_CMD_SIZE] =
{
	msh_cd, msh_echo, msh_env, msh_setenv,
	msh_unsetenv, msh_exit
};

# endif
