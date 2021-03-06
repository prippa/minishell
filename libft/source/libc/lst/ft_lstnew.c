/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:36:41 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:36:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_mem.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_obj;
	void	*data;

	data = NULL;
	if (content)
	{
		if (content_size)
		{
			if (!(data = ft_memalloc(content_size)))
				return (NULL);
			ft_memcpy(data, content, content_size);
		}
		else
			data = (void *)content;
	}
	else
		content_size = 0;
	if (!(new_obj = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new_obj->content = data;
	new_obj->content_size = content_size;
	return (new_obj);
}

t_list2	*ft_lst2new(void const *content, size_t content_size)
{
	t_list2	*new_obj;
	void	*data;

	data = NULL;
	if (content)
	{
		if (content_size)
		{
			if (!(data = ft_memalloc(content_size)))
				return (NULL);
			ft_memcpy(data, content, content_size);
		}
		else
			data = (void *)content;
	}
	else
		content_size = 0;
	if (!(new_obj = (t_list2 *)ft_memalloc(sizeof(t_list2))))
		return (NULL);
	new_obj->content = data;
	new_obj->content_size = content_size;
	return (new_obj);
}
