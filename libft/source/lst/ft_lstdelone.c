/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:19 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:37:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	if (!*lst)
		return ;
	if (del)
		del((*lst)->content, (*lst)->content_size);
	free(*lst);
	*lst = NULL;
}
