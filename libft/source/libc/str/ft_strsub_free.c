/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:08:20 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 17:08:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strsub_free(char **s, uint32_t start, size_t len)
{
	char	*tmp;

	if (!s || !*s)
		return (NULL);
	tmp = *s;
	if (!(*s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(*s, tmp + start, len);
	(*s)[len] = 0;
	free(tmp);
	return (*s);
}
