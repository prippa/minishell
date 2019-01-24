/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:33:35 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:33:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstpop(t_list **lst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(&tmp, del);
}

void	ft_lst2_pop_front(t_list2 **start, t_list2 **end,
			void (*del)(void *, size_t))
{
	ft_lst2del_by_obj(start, end, *start, del);
}

void	ft_lst2_pop_back(t_list2 **start, t_list2 **end,
			void (*del)(void *, size_t))
{
	ft_lst2del_by_obj(start, end, *end, del);
}
