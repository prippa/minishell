/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:43:53 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:43:54 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnjoin(char const *s1, char const *s2,
			size_t s1len, size_t s2len)
{
	char	*new_obj;

	if (!(new_obj = (char *)malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_strncpy(new_obj, s1, s1len);
	ft_strncpy(new_obj + s1len, s2, s2len);
	new_obj[s1len + s2len] = 0;
	return (new_obj);
}
