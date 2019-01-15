/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	while (*lst)
		ft_lstpop(lst, del);
}

void	ft_lst2del(t_list2 **start, t_list2 **end, void (*del)(void *, size_t))
{
	while (*start)
		ft_lst2_pop_front(start, end, del);
}

void	ft_lst2del_by_obj(t_list2 **start, t_list2 **end,
			t_list2 *obj, void (*del)(void *, size_t))
{
	if (!obj)
		return ;
	if (!obj->prev)
	{
		*start = (*start)->next;
		if (*start)
			(*start)->prev = NULL;
		else
			*end = NULL;
	}
	else if (!obj->next)
	{
		obj->prev->next = NULL;
		*end = obj->prev;
	}
	else
	{
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	ft_lstdelone((t_list **)(&obj), del);
}

void	ft_lstdel_content(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}
