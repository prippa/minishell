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

typedef struct	s_shell
{
	char		prompt[PROMPT_SIZE];
	char		curent_path[PATH_MAX + 1];
	t_list2		*env_start;
	t_list2		*env_end;
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

void			sh_fatal_err(const char *message);

# define GET_MEM(m, v, f, a ...) if (!(v = f(a))) sh_fatal_err(m)

void			sh_init(void);
void			sh_init_env(void);
t_bool			sh_is_dir(const char *path);
t_bool			sh_is_link(const char *path);
t_bool			sh_is_valid_path(const char *path);
// char			*sh_join_to_pwd(const char *name);
t_bool			sh_path_access(const char *path, const char *prefix);
void			sh_update_curent_dir_name(void);
void			sh_process_cmd(t_list2 **env_start, t_list2 **env_end,
					char **args);
void			sh_exec(const char *path, char **args);
void			sh_update_prompt(void);

char			*read_line(const char *prompt);

void			line_parser(void);

#endif
