#include <dirent.h>
#include "read_line.h"
#include "syntax_characters.h"
#include "builtin_static_arr.h"
#include "environ_manipulation.h"
#include "messages.h"

static void		rl_t_gm_push_cmd(t_list **m, const char *bc, const char *c)
{
	char	*cmd;
	t_list	*new_obj;

	if (ft_strnequ(bc, c, ft_strlen(bc)))
	{
		GET_MEM(MALLOC_ERR, cmd, ft_strdup, c);
	}
	else
		return ;
	GET_MEM(MALLOC_ERR, new_obj, ft_lstnew, cmd, 0);
	ft_lstadd(m, new_obj);
}

static void		rl_t_read_dir(t_list **m, char **paths, const char *bc)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*bin;

	while (*paths)
	{
		if (access(*paths, F_OK) || access(*paths, X_OK))
			continue ;
		if (!(dip = opendir(*paths)))
			sh_fatal_err(OPENDIR_FAILED);
		while ((dit = readdir(dip)))
		{
			GET_MEM(MALLOC_ERR, bin, ft_strjoin,
				*paths, (char[2]){UNIX_PATH_SEPARATOR, 0});
			GET_MEM(MALLOC_ERR, bin, ft_strjoin_free,
				&bin, dit->d_name, ft_strlen(bin), ft_strlen(dit->d_name));
			if (!access(bin, X_OK) && dit->d_type != DT_DIR)
				rl_t_gm_push_cmd(m, bc, dit->d_name);
			ft_memdel((void **)&bin);
		}
		if ((closedir(dip)) == ERR)
			sh_fatal_err(CLOSEDIR_FAILED);
		++paths;
	}
}

static t_list	*rl_t_get_matches(const char *bc)
{
	size_t	i;
	t_list	*m;
	char	**paths;
	char	*path_env;

	m = NULL;
	i = -1;
	while (++i < SH_CMD_SIZE)
		rl_t_gm_push_cmd(&m, bc, g_cmd_string[i]);
	if (!(path_env = env_get_vlu_by_key(sh()->env_start, PATH_ENV)))
		path_env = CUR_DIR;
	GET_MEM(MALLOC_ERR, paths, ft_strsplit, path_env, PATH_ENV_SEPARATOR);
	rl_t_read_dir(&m, paths, bc);
	ft_arrdel(&paths);
	return (m);
}

static char		*rl_t_get_cmd_from_line(void)
{
	char	*cmd;
	size_t	len;
	size_t	size;
	t_bool	space_flag;

	size = ft_strlen(rl()->line);
	space_flag = false;
	len = 0;
	while (size--)
	{
		if (rl()->line[size] == SEMICOLON_C)
			break ;
		if (ft_isspace(rl()->line[size]))
			space_flag = true;
		else if (space_flag && ft_isascii(rl()->line[size]))
			return (NULL);
		if (!space_flag)
			++len;
	}
	GET_MEM(MALLOC_ERR, cmd, ft_strsub,
		rl()->line, ft_strlen(rl()->line) - len, len);
	return (cmd);
}

void			rl_tab(void)
{
	char	*base_cmd;
	t_list	*matches;

	if (rl()->if_inhibitors_in_use_flag)
		return ;
	if (!(base_cmd = rl_t_get_cmd_from_line()))
		return ;
	if ((matches = rl_t_get_matches(base_cmd)))
	{
		ft_lstrev(&matches);
		rl_t_process_matches(matches, ft_strlen(base_cmd));
		ft_lstdel(&matches, ft_lstdel_content);
	}
	ft_memdel((void **)&base_cmd);
}
