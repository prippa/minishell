/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:10:15 by prippa            #+#    #+#             */
/*   Updated: 2017/10/26 18:10:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int32_t c, size_t len)
{
	uint8_t *ptr;
	uint8_t ch;

	ptr = (uint8_t *)b;
	ch = (uint8_t)c;
	while (len--)
		ptr[len] = ch;
	return (b);
}
