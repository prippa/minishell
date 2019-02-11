/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:22:03 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:22:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stdlib.h>
# include <stdint.h>

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int32_t c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int32_t c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int32_t c, size_t n);
int32_t		ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		*ft_memrev(void *dst, size_t n);
void		*ft_memjoin_free(void **dst, const void *src,
				size_t dstsize, size_t srcsize);
void		*ft_memjoin(const void *dst, const void *src,
				size_t dstsize, size_t srcsize);

#endif
