/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostruppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:13:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 16:15:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"
#include "ft_is.h"

void	ft_to_str_upper(char **str)
{
	char *tmp;

	tmp = *str;
	while (*tmp)
	{
		if (ft_islower(*tmp))
			*tmp = ft_toupper(*tmp);
		++tmp;
	}
}
