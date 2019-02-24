#include "minishell.h"
#include "messages.h"

static t_bool	msh_check_by_access(char *s, const char *path)
{
	if (access(s, F_OK))
	{
		PRINT_ERR(MSH_NO_FILE_OR_DIR, path);
	}
	else if (access(s, X_OK))
	{
		PRINT_ERR(MSH_PERM_DENIED, path);
	}
	else
		return (0);
	return (1);
}

t_bool			msh_check_path_permision(const char *path)
{
	char	*s;
	size_t	i;
	int32_t	status;

	if (!(s = ft_strdup(path)))
		msh_fatal_err(MALLOC_ERR);
	status = 0;
	i = -1;
	if (*s == UNIX_PATH_SEPARATOR)
		++i;
	while (s[++i])
		if (s[i] == UNIX_PATH_SEPARATOR)
		{
			s[i] = 0;
			if ((status = msh_check_by_access(s, path)))
				break ;
			s[i] = UNIX_PATH_SEPARATOR;
		}
	ft_memdel((void **)&s);
	return (status);
}
