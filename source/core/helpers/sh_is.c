#include "shell.h"
#include "messages.h"
#include <sys/stat.h>

t_bool		sh_is_dir(const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		sh_fatal_err(STAT_FAILED);
	return (S_ISDIR(sb.st_mode));
}

t_bool		sh_is_link(const char *path)
{
	struct stat	sb;

	if ((lstat(path, &sb)) == ERR)
		sh_fatal_err(LSTAT_FAILED);
	return (S_ISLNK(sb.st_mode));
}

t_bool		sh_is_valid_path(const char *path)
{
	uint16_t	i;

	i = 0;
	while (*path)
	{
		if (*path == UNIX_PATH_SEPARATOR)
			i = 0;
		else if (++i > FILE_NAME_MAX)
			return (true);
		++path;
	}
	return (false);
}
