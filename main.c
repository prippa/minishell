#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include <string.h>

#define SIZE 4096

typedef struct	s_lp_flags
{
	t_bool		any_char_in_cmd;
}				t_lp_flags;

typedef struct	s_line_parser
{
	t_list		*args;
	size_t		args_size;
	size_t		arg_buf_len;
	char		*arg;
	size_t		arg_len;
	t_lp_flags	f;
}				t_line_parser;
static const char	*g_cmd_string = " $;'\"\\";
#define LP_SNTX_ERR "syntax error near unexpected token '" &';' &'\''
int main(int argc, char const *argv[])
{
	ft_printf("%s\n", LP_SNTX_ERR);
	return 0;
}

