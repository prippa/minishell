/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:58:49 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:58:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	*ft_memrev(void *dst, size_t n)
{
	uint8_t	tmp;
	uint8_t	*ptr;
	size_t	i;

	if (!n)
		return (dst);
	ptr = (uint8_t *)dst;
	i = -1;
	while (--n > ++i)
	{
		tmp = ptr[i];
		ptr[i] = ptr[n];
		ptr[n] = tmp;
	}
	return (dst);
}
