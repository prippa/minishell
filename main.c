#include "get_next_line.h"
#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	char *line;
	while (get_next_line(0, &line) > 0)
		ft_printf("%s\n", line);
	return 0;
}

