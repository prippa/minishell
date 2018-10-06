/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:10:48 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 16:10:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char **dst, const char *src)
{
	char *tmp;

	tmp = *dst;
	if (!(*dst = ft_strdup(src)))
		return (NULL);
	free(tmp);
	return (*dst);
}
