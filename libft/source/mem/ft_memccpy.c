/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:28:28 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 14:28:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int32_t c, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;
	uint8_t	ch;

	ptr1 = (uint8_t *)dst;
	ptr2 = (uint8_t *)src;
	ch = (uint8_t)c;
	while (n--)
		if ((*ptr1++ = *ptr2++) == ch)
			return (ptr1);
	return (NULL);
}
