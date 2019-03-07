#include <dirent.h>
#include "read_line.h"
#include "messages.h"

static char	*rl_t_get_path_to_bin(const char *path, const char *file)
{
	char *bin;

	GET_MEM(MALLOC_ERR, bin, ft_strjoin,
		path, (char[2]){UNIX_PATH_SEPARATOR, 0});
	GET_MEM(MALLOC_ERR, bin, ft_strjoin_free,
		&bin, file, ft_strlen(bin), ft_strlen(file));
	return (bin);
}

void		rl_t_read_dir(t_list **m, char **paths, const char *bc)
{
	size_t			i;
	DIR				*dip;
	struct dirent	*dit;
	char			*bin;

	i = -1;
	while (paths[++i])
	{
		if (access(paths[i], F_OK) || access(paths[i], X_OK))
			continue ;
		if (!(dip = opendir(paths[i])))
			sh_fatal_err(OPENDIR_FAILED);
		while ((dit = readdir(dip)))
		{
			bin = rl_t_get_path_to_bin(paths[i], dit->d_name);
			if (!access(bin, X_OK) && dit->d_type != DT_DIR)
				rl_t_gm_push_cmd(m, bc, dit->d_name);
			ft_memdel((void **)&bin);
		}
		if ((closedir(dip)) == ERR)
			sh_fatal_err(CLOSEDIR_FAILED);
	}
}
