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
# include "ft_printf.h"

# define PATH_MAX				4096
# define FILE_NAME_MAX			255
# define PROMPT_SIZE			FILE_NAME_MAX * 2

typedef struct	s_env
{
	char		*env;
	size_t		index;
}				t_env;

typedef struct	s_minishel
{
	char		prompt[PROMPT_SIZE];
	char		curent_path[PATH_MAX + 1];
	t_list2		*env_start;
	t_list2		*env_end;
	size_t		env_size;
	char		*line;
	size_t		i;
}				t_minishel;

extern t_bool		g_ok;
extern int32_t		g_exec_code;
extern t_minishel	g_msh;

# define PE_P(f, a ...) ft_dprintf(STDERR_FILENO, f, a)
# define PE_NL ft_putendl_fd(EMPTY_STR, STDERR_FILENO)
# define PE_SE(ec) g_exec_code = ec; g_ok = false
# define PRINT_ERR(ec, f, a ...) PE_P(f, a); PE_NL; PE_SE(ec)

void			msh_init(void);
void			msh_init_env(void);
void			msh_del_env_list(void *content, size_t content_size);
void			msh_del_env_body(t_env *e);
void			msh_del_commands_list(void *content, size_t content_size);
void			msh_fatal_err(const char *message);
t_bool			msh_is_dir(const char *path);
t_bool			msh_is_valid_path(const char *path);
t_bool			msh_path_access(const char *path, const char *prefix);
void			msh_update_curent_dir_name(void);
char			*msh_getenv_vlu_by_key(const char *key);
t_list2			*msh_getenv_obj_by_key(const char *key);
void			msh_setenv_one_env(const char *key, const char *value);
void			msh_unsetenv_one_env(const char *env);

void			line_syntax(void);
void			line_parser(void);
void			msh_process_cmd(char **args);
void			msh_exec(const char *path, char **args);

void			msh_update_prompt(void);

#endif
