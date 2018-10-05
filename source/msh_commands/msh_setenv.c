/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:56 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_setenv_print_usage(t_msh *msh)
{
	ft_dprintf(2, MSH_SETENV_USG);
	msh->execute_flag = false;
}

void		msh_setenv(t_msh *msh, char **args)
{
	t_list2	*new_obj;
	t_env	e;
	size_t	separate_index;
	
	if (!*args)
		msh_setenv_print_usage(msh);
	else
	{
		while (*args)
		{
			separate_index = ft_strchr(*args, '=') - *args;
			(*args)[separate_index] = 0;
			if (!(e.name = ft_strdup(*args)))
				msh_error_exit(msh, MALLOC_ERR);
			if (!(e.arg = ft_strdup(&(*args)[separate_index + 1])))
				msh_error_exit(msh, MALLOC_ERR);
			if (!(new_obj = ft_lst2new(&e, sizeof(t_env))))
				msh_error_exit(msh, MALLOC_ERR);
			ft_lst2_push_back(&msh->env_start, &msh->env_end, new_obj);
			++args;
		}
	}
}
