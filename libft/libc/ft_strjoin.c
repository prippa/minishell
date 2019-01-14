/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:54:41 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:54:54 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2,
			size_t s1len, size_t s2len)
{
	char	*new_obj;

	if (!(new_obj = (char *)malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_strcpy(new_obj, s1);
	ft_strncpy(new_obj + s1len, s2, s2len);
	*(new_obj + s1len + s2len) = 0;
	return (new_obj);
}
