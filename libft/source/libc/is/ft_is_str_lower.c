/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrlowercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:21:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:23:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is.h"

int32_t	ft_is_str_lower(const char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str) && ft_isupper(*str))
			return (0);
		++str;
	}
	return (1);
}
