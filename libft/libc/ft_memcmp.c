/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:19:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/05 13:47:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t *ptr1;
	uint8_t *ptr2;

	ptr1 = (uint8_t *)s1;
	ptr2 = (uint8_t *)s2;
	while (n--)
		if (*ptr1++ != *ptr2++)
			return (*(ptr1 - 1) - *(ptr2 - 1));
	return (0);
}
