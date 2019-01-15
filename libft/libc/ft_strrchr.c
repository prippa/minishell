/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:17:06 by prippa            #+#    #+#             */
/*   Updated: 2017/10/31 15:17:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

char	*ft_strrchr(const char *s, int32_t c)
{
	char *tmp;
	char ch;

	tmp = NULL;
	ch = c;
	while (*s)
		if (*s++ == ch)
			tmp = (char *)(s - 1);
	if (*s == ch)
		return ((char *)s);
	return (tmp);
}
