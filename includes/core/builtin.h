/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:18:20 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 20:18:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct	s_builtin
{
	t_list2		**env_start;
	t_list2		**env_end;
	char		**args;
}				t_build;

void			sh_cd(t_build *b);
void			sh_echo(t_build *b);
void			sh_env(t_build *b);
void			sh_setenv(t_build *b);
void			sh_unsetenv(t_build *b);
void			sh_exit(t_build *b);

int32_t			sh_setenv_one_env(t_list2 **env_start, t_list2 **env_end,
					const char *env, t_bool strictly_valid_flag);
void			sh_process_cmd(t_build *b, const char *cmd_prefix);
void			sh_exec(const char *path, t_build *b);

# define SH_CMD_SIZE	6

# define CD_CMD			"cd"
# define ECHO_CMD		"echo"
# define ENV_CMD		"env"
# define SETENV_CMD		"setenv"
# define UNSETENV_CMD	"unsetenv"
# define EXIT_CMD		"exit"

#endif
