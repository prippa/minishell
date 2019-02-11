/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:22:37 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:22:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TO_H
# define FT_TO_H

# include <stdint.h>

int32_t		ft_toupper(int32_t c);
int32_t		ft_tolower(int32_t c);
void		ft_to_str_lower(char **str);
void		ft_to_str_upper(char **str);

#endif
