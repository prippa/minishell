#ifndef FT_PUT_H
# define FT_PUT_H

#include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int32_t n);
void		ft_putchar_fd(char c, int32_t fd);
void		ft_putstr_fd(char const *s, int32_t fd);
void		ft_putendl_fd(char const *s, int32_t fd);
void		ft_putnbr_fd(int32_t n, int32_t fd);
void		ft_putarr(char **arr);
void		ft_putarr_fd(char **arr, int32_t fd);

#endif
