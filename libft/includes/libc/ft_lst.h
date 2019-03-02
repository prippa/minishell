/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:21:55 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:21:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_list2
{
	void			*content;
	size_t			content_size;
	struct s_list2	*next;
	struct s_list2	*prev;
}					t_list2;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **lst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **lst, t_list *new_obj);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpop(t_list **lst, void (*del)(void *, size_t));
void				ft_lstrev(t_list **lst);

t_list2				*ft_lst2new(void const *content, size_t content_size);
void				ft_lst2del(t_list2 **start, t_list2 **end,
						void (*del)(void *, size_t));
void				ft_lst2del_by_obj(t_list2 **start, t_list2 **end,
						t_list2 *obj, void (*del)(void *, size_t));
void				ft_lst2_push_front(t_list2 **start, t_list2 **end,
						t_list2 *new_obj);
void				ft_lst2_push_back(t_list2 **start, t_list2 **end,
						t_list2 *new_obj);
void				ft_lst2iter(t_list2 *start, void (*f)(t_list2 *elem));
void				ft_lst2_pop_front(t_list2 **start, t_list2 **end,
						void (*del)(void *, size_t));
void				ft_lst2_pop_back(t_list2 **start, t_list2 **end,
						void (*del)(void *, size_t));
void				ft_lst2rev(t_list2 **start, t_list2 **end);

size_t				ft_lstsize(t_list *start);
void				ft_lstdel_content(void *content, size_t content_size);

#endif
