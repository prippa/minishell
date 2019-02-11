/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:22:21 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:22:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include <unistd.h>
# include <stdint.h>

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
