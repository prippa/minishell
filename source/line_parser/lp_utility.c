#include "lp_commands.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	lp_free(t_line_parser *lp)
{
	ft_strdel(&lp->arg);
	ft_lstdel(&lp->args, ft_lstdel_content);
}

void		lp_error_exit(t_minishel *msh, t_line_parser *lp,
			const char *message)
{
	lp_free(lp);
	msh_error_exit(msh, message);
}

void		lp_print_error(t_line_parser *lp, uint16_t key)
{
	if (key == SEMI_SYNTAX_KEY)
		ft_dprintf(STDERR_FILENO,
			"syntax error near unexpected token '%c'\n", SEMICOLON_C);
}

void		lp_quote_read(t_minishel *msh, t_line_parser *lp,
				t_func_cmd func)
{
	char *new_line;

	ft_putstr("> ");
	if (get_next_line(STDIN_FILENO, &new_line) == ERR)
		lp_error_exit(msh, lp, OTHER_ERR);
	if (!(ft_strjoin_free(&msh->line, "\n", ft_strlen(msh->line), 1)))
		lp_error_exit(msh, lp, MALLOC_ERR);
	if (!(ft_strjoin_free(&msh->line, new_line,
		ft_strlen(msh->line), ft_strlen(new_line))))
			lp_error_exit(msh, lp, MALLOC_ERR);
	lp_write_to_arg_buf_char(msh, lp, '\n');
	ft_strdel(&new_line);
	func(msh, lp);
}
