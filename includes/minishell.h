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

# include "../libft/includes/libc/libft.h"
# include "../libft/includes/printf/ft_printf.h"

# define PATH_MAX				4096
# define FILE_NAME_MAX			255

# define PROMPT_SIZE			FILE_NAME_MAX + 20
# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'

# define HOME_ENV				"HOME"
# define PWD_ENV				"PWD"
# define OLDPWD_ENV				"OLDPWD"

typedef struct		s_command
{
	char			**args;
}					t_command;

typedef struct		s_env
{
	char			*env;
	size_t			index;
}					t_env;

typedef struct		s_minishel
{
	char			prompt[PROMPT_SIZE];
	char			curent_path[PATH_MAX + 1];
	t_list2			*env_start;
	t_list2			*env_end;
	size_t			env_size;
	char			*line;
	size_t			i;
	t_list			*commands;
	t_bool			success_exec;
}					t_minishel;

void				msh_free(t_minishel *msh);
void				msh_del_env_list(void *content, size_t content_size);
void				msh_del_env_body(t_env *e);
void				msh_del_commands_list(void *content, size_t content_size);
void				msh_error_exit(t_minishel *msh, const char *message);
void				msh_execute_command(t_minishel *msh);
void				msh_print_error(t_minishel *msh, const char *message);
t_bool				msh_is_dir(t_minishel *msh, const char *path);
t_bool				msh_is_valid_path(const char *path);
void				msh_set_pwd(t_minishel *msh, const char *pwd_name);
void				msh_update_curent_dir_name(t_minishel *msh);
const char			*msh_env_get_value_by_key(t_list2 *start,
						const char *env, size_t len);
t_list2				*msh_env_get_obj_by_key(t_list2 *start,
						const char *env, size_t len);
void				msh_setenv_one_env(t_minishel *msh, const char *env);
void				msh_unsetenv_one_env(t_minishel *msh, const char *env);

void				line_lexer(t_minishel *msh);
void				line_parser(t_minishel *msh);

void				msh_cd(t_minishel *msh, char **args);
void				msh_echo(t_minishel *msh, char **args);
void				msh_env(t_minishel *msh, char **args);
void				msh_setenv(t_minishel *msh, char **args);
void				msh_unsetenv(t_minishel *msh, char **args);
void				msh_exit(t_minishel *msh, char **args);

t_bool				msh_base_cmd_search(t_minishel *msh, char **args);
t_bool				msh_full_path_cmd_search(t_minishel *msh,
						const char *full_path, char **args);
t_bool				msh_env_path_cmd_search(t_minishel *msh, char **args);

void				msh_fork_exec(t_minishel *msh,
						const char *path, char **args);

#endif
