# include <libft.h>

int32_t	ft_isalnum_in_case(int32_t c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}
