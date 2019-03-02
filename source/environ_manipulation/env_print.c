/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:36:26 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 16:36:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "ft_printf.h"

static void	env_print_f(t_list2 *elem)
{
	t_env *e;

	e = (t_env *)elem->content;
	ft_printf("%s=%s\n", e->key, e->value);
}

void		env_print(t_list2 *env_start)
{
	ft_lst2iter(env_start, env_print_f);
}
