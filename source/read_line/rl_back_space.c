#include "read_line.h"

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
