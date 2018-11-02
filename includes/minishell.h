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
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT_SIZE	512

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
	char			*line;
	t_bool			execute_flag;
}					t_msh;

void				msh_free(t_msh *msh);
void				msh_error_exit(t_msh *msh, const char *message);
void				msh_update_curent_dir_name(t_msh *msh);
void				msh_del_env_list(void *content, size_t content_size);
void				msh_execute_command(t_msh *msh);
void				msh_print_error(t_msh *msh, const char *message);

void				msh_cd(t_msh *msh, char **args);
void				msh_echo(t_msh *msh, char **args);
void				msh_env(t_msh *msh, char **args);
void				msh_setenv(t_msh *msh, char **args);
void				msh_unsetenv(t_msh *msh, char **args);
void				msh_exit(t_msh *msh, char **args);

#endif
