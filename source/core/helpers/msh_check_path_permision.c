#include "minishell.h"
#include "messages.h"

static t_bool	msh_check_by_access(char *s, const char *path,
					const char *prefix)
{
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(NO_FILE_OR_DIR, path);
	}
	else if (access(s, X_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(PERM_DENIED, path);
	}
	else
		return (false);
	return (true);
}

t_bool			msh_check_path_permision(const char *path, const char *prefix)
{
	char	*s;
	size_t	i;

	if (!(s = ft_strdup(path)))
		msh_fatal_err(MALLOC_ERR);
	if ((i = -1) && *s == UNIX_PATH_SEPARATOR)
		++i;
	while (s[++i])
		if (s[i] == UNIX_PATH_SEPARATOR)
		{
			s[i] = 0;
			if (msh_check_by_access(s, path, prefix))
			{
				ft_memdel((void **)&s);
				return (true);
			}
			s[i] = UNIX_PATH_SEPARATOR;
		}
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		PRINT_ERR(NO_FILE_OR_DIR, path);
		return (true);
	}
	ft_memdel((void **)&s);
	return (false);
}
