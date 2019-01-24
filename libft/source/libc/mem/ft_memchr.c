/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:50:26 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 17:50:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	*ft_memchr(const void *s, int32_t c, size_t n)
{
	uint8_t	*ptr;
	uint8_t	ch;

	ptr = (uint8_t *)s;
	ch = (uint8_t)c;
	while (n--)
		if (*ptr++ == ch)
			return (ptr - 1);
	return (NULL);
}
