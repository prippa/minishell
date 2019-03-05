#include "shell.h"
#include "read_line.h"

void		sh_handle_sigint_rl(int sig)
{
	if (sig == SIGINT)
	{
		ft_memdel((void **)&rl()->line);
		PRINT_ERR(SIGINT, EMPTY_STR, NULL);
		sh_update_prompt();
		ft_putstr(sh()->prompt);
	}
}

void		sh_handle_sigint_base(int sig)
{
	if (sig == SIGINT)
	{
		PRINT_ERR(SIGINT, EMPTY_STR, NULL);
		sh_update_prompt();
		ft_putstr(sh()->prompt);
	}
}

void		sh_handle_sigint_incase(int sig)
{
	if (sig == SIGINT)
	{
		PRINT_ERR(SIGINT, EMPTY_STR, NULL);
	}
}
