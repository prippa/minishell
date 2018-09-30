#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "messages.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT_SIZE	512
# define FILE_NAME_MAX	256

typedef struct		s_env
{
	char			*name;
	char			*arg;
}					t_env;

typedef struct		s_msh
{
	char			prompt[PROMPT_SIZE];
	char			curent_dir_name[FILE_NAME_MAX];
	t_list2			*env_start;
	t_list2			*env_end;
	char			*line;
}					t_msh;

void				msh_free(t_msh *msh);
void				msh_error_exit(t_msh *msh, const char *message);
void				msh_update_curent_dir_name(t_msh *msh);
void				msh_parse_line(t_msh *msh);

# endif
