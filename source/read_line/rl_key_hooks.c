#include "read_line.h"
#include "builtin.h"

void		rl_ctrl_d(void)
{
	if (ft_strequ(rl()->line, EMPTY_STR))
		sh_exit(NULL);
}

void		rl_back_space(void)
{
	if (rl()->len)
	{
		--rl()->len;
		GET_MEM(MALLOC_ERR, rl()->line, ft_strsub_free,
			&rl()->line, 0, rl()->len);
		ft_putstr("\b  \b\b");
	}
}

int32_t		rl_new_line(void)
{
	int32_t	ls_res;

	ft_putstr("\n");
	if (!(ls_res = rl_line_syntax()))
		return (RL_BREAK);
	ls_print_info(ls_res);
	if (ls_res < 0)
		return (RL_BREAK);
	if (rl()->new_line_flag)
		rl_join_char_to_line('\n');
	if (ls_res > 0)
	{
		rl()->len = 0;
		rl()->if_inhibitors_in_use_flag = true;
	}
	return (RL_CONTINUE);
}
