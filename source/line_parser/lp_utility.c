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

void		lp_print_error(uint16_t key)
{
	if (key == SEMI_SYNTAX_KEY)
		ft_dprintf(STDERR_FILENO,
			"syntax error near unexpected token '%c'\n", SEMICOLON_C);
	else if (key = UNEXPECTED_EOF)
		ft_dprintf(STDERR_FILENO,
			"\nunexpected EOF while looking for matching quotes\n");
}

t_bool		lp_quote_read(t_minishel *msh, t_line_parser *lp,
				t_func_cmd func)
{
	char *new_line;

	new_line = NULL;
	ft_putstr("> ");
	if (get_next_line(STDIN_FILENO, &new_line) == ERR)
		lp_error_exit(msh, lp, OTHER_ERR);
	if (!new_line)
		return (false);
	if (!(ft_strjoin_free(&msh->line, "\n", ft_strlen(msh->line), 1)))
		lp_error_exit(msh, lp, MALLOC_ERR);
	if (!(ft_strjoin_free(&msh->line, new_line,
		ft_strlen(msh->line), ft_strlen(new_line))))
			lp_error_exit(msh, lp, MALLOC_ERR);
	lp_write_to_arg_buf_char(msh, lp, '\n');
	ft_strdel(&new_line);
	return (func(msh, lp));
}
