/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:34:00 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:34:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/includes/libc/libft.h"
# include "../../libft/includes/printf/ft_printf.h"
# include "../../libft/includes/get_next_line/get_next_line.h"
# include <sys/types.h>

typedef struct s_env		t_env;
typedef struct s_minishel	t_minishel;

extern t_bool		g_ok;
extern t_minishel	g_msh;

# define PRINT_ERR(f, a ...) ft_dprintf(STDERR_FILENO, f, a); g_ok = false;

# define PATH_MAX				4096
# define FILE_NAME_MAX			255

# define PROMPT_SIZE			FILE_NAME_MAX * 2
# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'
# define PATH_ENV_SEPARATOR		':'

# define HOME_ENV				"HOME"
# define PWD_ENV				"PWD"
# define OLDPWD_ENV				"OLDPWD"
# define PATH_ENV				"PATH"

struct			s_env
{
	char		*env;
	size_t		index;
};

struct			s_minishel
{
	char		prompt[PROMPT_SIZE];
	char		curent_path[PATH_MAX + 1];
	t_list2		*env_start;
	t_list2		*env_end;
	size_t		env_size;
	char		*line;
	size_t		i;
};

void			msh_init(void);
void			msh_del_env_list(void *content, size_t content_size);
void			msh_del_env_body(t_env *e);
void			msh_del_commands_list(void *content, size_t content_size);
void			msh_fatal_err(const char *message);
t_bool			msh_is_dir(const char *path);
t_bool			msh_is_valid_path(const char *path);
void			msh_update_curent_dir_name(void);
const char		*msh_getenv_value_by_key(t_list2 *start,
					const char *env, size_t len);
t_list2			*msh_getenv_obj_by_key(t_list2 *start,
					const char *env, size_t len);
void			msh_setenv_one_env(const char *key, const char *value);
void			msh_unsetenv_one_env(const char *env);

void			line_syntax(void);
void			line_parser(void);
void			msh_process_cmd(char **args);
void			msh_exec(const char *path, char **args);

void			msh_cd(char **args);
void			msh_echo(char **args);
void			msh_env(char **args);
void			msh_setenv(char **args);
void			msh_unsetenv(char **args);
void			msh_exit(char **args);

void			msh_on_base_signals(void);
void			msh_on_dfl_signals(void);
void			msh_off_signals(void);
void			msh_update_prompt(void);

#endif
