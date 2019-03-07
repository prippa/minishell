#include "read_line.h"
#include "builtin.h"

void		rl_ctrl_d(void)
{
	if (ft_strequ(rl()->line, EMPTY_STR))
		sh_exit(NULL);
}
