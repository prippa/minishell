#ifndef MESSAGES_H
# define MESSAGES_H

# define SHELL_NAME		"minishell"

# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'
# define PATH_ENV_SEPARATOR		':'

# define HOME_ENV		"HOME"
# define PWD_ENV		"PWD"
# define OLDPWD_ENV		"OLDPWD"
# define PATH_ENV		"PATH"
# define SHELL_ENV		"SHELL"
# define PREV_CMD_ENV	"_"
# define SHELL_LVL_ENV	"SHLVL"

# define CHDIR_FAILED 	"chdir() failed"
# define GETCWD_FAILED 	"getcwd() failed"
# define FORK_FAILED	"fork() failed"
# define WAIT_FAILED	"wait() failed"
# define STAT_FAILED	"stat() failed"

#define PERM_DENIED		"'%s': Permission denied"
#define NO_FILE_OR_DIR	"'%s': No such file or directory"
#define IS_A_DIR		"'%s': Is a directory"

#define MSH_PERM_DENIED SHELL_NAME ": " PERM_DENIED
#define MSH_NO_FILE_OR_DIR SHELL_NAME ": " NO_FILE_OR_DIR
#define MSH_IS_A_DIR SHELL_NAME ": " IS_A_DIR

#endif
