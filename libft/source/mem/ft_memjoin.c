/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:24:03 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 19:24:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memjoin(const void *dst, const void *src,
			size_t dstsize, size_t srcsize)
{
	void *new_obj;

	if (!(new_obj = (void *)malloc(sizeof(void) * (dstsize + srcsize))))
		return (NULL);
	ft_memcpy(new_obj, dst, dstsize);
	ft_memcpy(new_obj + dstsize, src, srcsize);
	return (new_obj);
}
