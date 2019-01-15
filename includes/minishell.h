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

# include "libft.h"
# include "messages.h"

# define PATH_MAX		4096
# define PROMPT_SIZE	PATH_MAX + 256

typedef struct		s_command
{
	char			**args;
}					t_command;

typedef struct		s_env
{
	char			*value;
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
	t_list			*commands;
	t_bool			execute_flag;
}					t_minishel;

void				msh_free(t_minishel *msh);
void				msh_del_env_list(void *content, size_t content_size);
void				msh_del_env_body(t_env *e);
void				msh_error_exit(t_minishel *msh, const char *message);
void				msh_execute_command(t_minishel *msh);
void				msh_print_error(t_minishel *msh, const char *message);
char				*msh_env_get_arg_by_name(t_list2 *start,
						const char *value, size_t len);
t_list2				*msh_env_get_obj_by_name(t_list2 *start,
						const char *value, size_t len);
void				msh_setenv_one_value(t_minishel *msh, const char *value);
void				msh_unsetenv_one_value(t_minishel *msh, const char *value);

void				msh_line_parser(t_minishel *msh);

void				msh_cd(t_minishel *msh, char **args);
void				msh_echo(t_minishel *msh, char **args);
void				msh_env(t_minishel *msh, char **args);
void				msh_setenv(t_minishel *msh, char **args);
void				msh_unsetenv(t_minishel *msh, char **args);
void				msh_exit(t_minishel *msh, char **args);

#endif
