/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:31:50 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 12:31:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define SHELL_NAME		"minishell"

# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'
# define PATH_ENV_SEPARATOR		':'

# define CUR_DIR				"."
# define PREV_DIR				".."

# define HOME_ENV		"HOME"
# define PWD_ENV		"PWD"
# define OLDPWD_ENV		"OLDPWD"
# define PATH_ENV		"PATH"
# define SHELL_ENV		"SHELL"
# define PREV_CMD_ENV	"_"
# define SHELL_LVL_ENV	"SHLVL"

# define DEFAULT_BIN_PATH	"/bin"

# define CHDIR_FAILED 	"chdir() failed"
# define GETCWD_FAILED 	"getcwd() failed"
# define FORK_FAILED	"fork() failed"
# define WAIT_FAILED	"wait() failed"
# define STAT_FAILED	"stat() failed"
# define LSTAT_FAILED	"lstat() failed"

# define PERM_DENIED		"'%s': Permission denied"
# define NO_FILE_OR_DIR		"'%s': No such file or directory"
# define IS_A_DIR			"'%s': Is a directory"
# define TO_MANY_ARGS		"Too many arguments"

# define SH_PERM_DENIED 	SHELL_NAME ": " PERM_DENIED
# define SH_NO_FILE_OR_DIR	SHELL_NAME ": " NO_FILE_OR_DIR
# define SH_IS_A_DIR		SHELL_NAME ": " IS_A_DIR

#endif
