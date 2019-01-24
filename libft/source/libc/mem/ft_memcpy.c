/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:34:25 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 13:34:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;

	ptr1 = (uint8_t *)dst;
	ptr2 = (uint8_t *)src;
	while (n--)
		ptr1[n] = ptr2[n];
	return (dst);
}
