/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:22:12 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:22:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTHER_H
# define FT_OTHER_H

# include <stdlib.h>
# include <stdint.h>

int32_t		ft_atoi(const char *str);
intmax_t	ft_atoi_max(char *str);
intmax_t	ft_atoi_base(const char *str, int32_t base);
char		*ft_itoa(int32_t n);
char		*ft_itoa_max(intmax_t n);
char		*ft_itoa_base(uintmax_t num, int32_t base, int32_t letter);
int32_t		ft_base(const char c);
uint16_t	ft_nbrlen(intmax_t nb);
void		ft_clear(void);
void		ft_perror_exit(const char *message);
void		ft_fatal_err_exit(const char *message);

#endif
