#include "ft_str.h"
#include "ft_def.h"

int32_t		ft_is_str_empty(const char *str)
{
	if (!ft_strcmp(str, EMPTY_STR))
		return (true);
	return (false);
}
