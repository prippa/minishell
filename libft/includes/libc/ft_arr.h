/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:20:43 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:20:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include <stdlib.h>
# include <stdint.h>

char		**ft_arrnew(size_t y, size_t x, int32_t c);
size_t		ft_arrlen(char **arr);
void		ft_arrdel(char ***arr);

#endif
