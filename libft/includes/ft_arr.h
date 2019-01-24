#ifndef FT_ARR_H
# define FT_ARR_H

#include <stdlib.h>

char		**ft_arrnew(size_t y, size_t x, int32_t c);
size_t		ft_arrlen(char **arr);
void		ft_arrdel(char ***arr);

#endif
