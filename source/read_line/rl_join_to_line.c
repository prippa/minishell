#include "read_line.h"

void			rl_join_char_to_line(char c)
{
	GET_MEM(MALLOC_ERR, rl()->line, ft_strjoin_free,
		&rl()->line, &c, ft_strlen(rl()->line), 1);
	++rl()->len;
}

void			rl_join_str_to_line(char *str)
{
	size_t str_len;

	str_len = ft_strlen(str);
	GET_MEM(MALLOC_ERR, rl()->line, ft_strjoin_free,
		&rl()->line, str, ft_strlen(rl()->line), str_len);
	rl()->len += str_len;
}
