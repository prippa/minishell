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

void	sh_cd(char **args);
void	sh_echo(char **args);
void	sh_env(char **args);
void	sh_setenv(char **args);
void	sh_unsetenv(char **args);
void	sh_exit(char **args);

# define SH_CMD_SIZE	6

# define CD_CMD			"cd"
# define ECHO_CMD		"echo"
# define ENV_CMD		"env"
# define SETENV_CMD		"setenv"
# define UNSETENV_CMD	"unsetenv"
# define EXIT_CMD		"exit"

#endif
