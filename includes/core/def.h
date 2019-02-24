#ifndef DEF_H
# define DEF_H

# include "ft_printf.h"

# define SHELL_NAME				"minishell"

# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'
# define PATH_ENV_SEPARATOR		':'

# define HOME_ENV				"HOME"
# define PWD_ENV				"PWD"
# define OLDPWD_ENV				"OLDPWD"
# define PATH_ENV				"PATH"
# define SHELL_ENV				"SHELL"
# define PREV_CMD_ENV			"_"
# define SHELL_LVL_ENV			"SHLVL"

# define PE_PNL ft_putchar_fd('\n', STDERR_FILENO);
# define PE_P(f, a ...) ft_dprintf(STDERR_FILENO, f, a); PE_PNL
# define PE_DO g_ok = false;
# define PRINT_ERR(f, a ...) PE_P(f, a) PE_DO

#endif