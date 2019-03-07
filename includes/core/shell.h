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
# include <termios.h>

# define PATH_MAX		4096
# define FILE_NAME_MAX	255
# define PROMPT_SIZE	FILE_NAME_MAX * 2

typedef struct		s_shell
{
	struct termios	oldtio;
	char			prompt[PROMPT_SIZE];
	char			curent_path[PATH_MAX + 1];
	t_list2			*env_start;
	t_list2			*env_end;
	char			*line;
	size_t			i;
	t_bool			env_exec_flag;
	t_bool			ok;
	int32_t			exec_code;
	char			*pwd;
}					t_shell;

t_shell			*sh(void);

# define PE_P(f, a ...) ft_dprintf(STDERR_FILENO, f, a)
# define PE_NL ft_putendl_fd(EMPTY_STR, STDERR_FILENO)
# define PE_SE(ec) sh()->exec_code = ec; sh()->ok = false
# define PRINT_ERR(ec, f, a ...) PE_P(f, a); PE_NL; PE_SE(ec)

void				sh_fatal_err(const char *message);

# define GET_MEM(m, v, f, a ...) if (!(v = f(a))) sh_fatal_err(m)

void				sh_handle_sigint_rl(int sig);
void				sh_handle_sigint_base(int sig);
void				sh_handle_sigint_incase(int sig);
void				sh_init(void);
void				sh_init_env(void);
void				sh_init_termios(void);
t_bool				sh_is_dir(const char *path);
t_bool				sh_is_valid_path(const char *path);
t_bool				sh_path_access(const char *path, const char *prefix);
char				*sh_join_path_to_pwd(const char *cur_pwd, const char *path);
void				sh_update_curent_dir_name(void);
void				sh_update_prompt(t_bool ok);

char				*read_line(void);

void				line_parser(void);

#endif
