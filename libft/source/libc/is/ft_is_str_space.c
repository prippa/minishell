#include "ft_is.h"

int32_t	ft_is_str_space(const char *str)
{
	while (*str)
		if (!ft_isspace(*str++))
			return (0);
	return (1);
}
