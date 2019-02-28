/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:34:00 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:34:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"

# define PATH_MAX		4096
# define FILE_NAME_MAX	255
# define PROMPT_SIZE	FILE_NAME_MAX * 2

typedef struct	s_env
{
	char		*env;
	size_t		index;
}				t_env;

typedef struct	s_shell
{
	char		prompt[PROMPT_SIZE];
	char		curent_path[PATH_MAX + 1];
	t_list2		*env_start;
	t_list2		*env_end;
	size_t		env_size;
	char		*line;
	size_t		i;
}				t_shell;

extern t_bool	g_ok;
extern int32_t	g_exec_code;
extern t_shell	g_sh;

# define PE_P(f, a ...) ft_dprintf(STDERR_FILENO, f, a)
# define PE_NL ft_putendl_fd(EMPTY_STR, STDERR_FILENO)
# define PE_SE(ec) g_exec_code = ec; g_ok = false
# define PRINT_ERR(ec, f, a ...) PE_P(f, a); PE_NL; PE_SE(ec)

void			sh_init(void);
void			sh_init_env(void);
void			sh_del_env_list(void *content, size_t content_size);
void			sh_del_env_body(t_env *e);
void			sh_del_commands_list(void *content, size_t content_size);
void			sh_fatal_err(const char *message);
t_bool			sh_is_dir(const char *path);
t_bool			sh_is_valid_path(const char *path);
t_bool			sh_path_access(const char *path, const char *prefix);
void			sh_update_curent_dir_name(void);
char			*sh_getenv_vlu_by_key(const char *key, size_t len);
t_list2			*sh_getenv_obj_by_key(const char *key, size_t len);
void			sh_setenv_one_env(const char *key, const char *value);
void			sh_unsetenv_one_env(const char *env);
void			sh_process_cmd(char **args);
void			sh_exec(const char *path, char **args);
void			sh_update_prompt(void);

char			*read_line(const char *prompt);

void			line_parser(void);

#endif
