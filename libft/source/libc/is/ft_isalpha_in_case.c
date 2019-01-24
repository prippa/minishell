#include "ft_is.h"

int32_t	ft_isalpha_in_case(int32_t c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}