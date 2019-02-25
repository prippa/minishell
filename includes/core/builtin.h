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

void	msh_cd(char **args);
void	msh_echo(char **args);
void	msh_env(char **args);
void	msh_setenv(char **args);
void	msh_unsetenv(char **args);
void	msh_exit(char **args);

# define MSH_CMD_SIZE	6

# define CD_CMD			"cd"
# define ECHO_CMD		"echo"
# define ENV_CMD		"env"
# define SETENV_CMD		"setenv"
# define UNSETENV_CMD	"unsetenv"
# define EXIT_CMD		"exit"

#endif
