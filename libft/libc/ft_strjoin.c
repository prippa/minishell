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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_obj;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	if (!(new_obj = (char *)malloc(sizeof(char) * (ft_strlen(s1) + s2len + 1))))
		return (NULL);
	ft_strcpy(new_obj, s1);
	ft_strcpy(new_obj + s2len, s2);
	return (new_obj);
}
