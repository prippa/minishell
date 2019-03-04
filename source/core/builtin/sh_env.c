/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:51 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtin.h"
#include "environ_manipulation.h"

#define ENV_I_F		"-i"

static void		sh_env_check_kv(t_bool i_flag, t_build *b)
{
	(void)i_flag;
	(void)b;
}

static t_bool	sh_env_check_flag(char ***args)
{
	t_bool f;

	f = false;
	while (**args)
	{
		if (!ft_strcmp(ENV_I_F, **args))
			f = true;
		else
			break ;
		++(*args);
	}
	return (f);
}

void			sh_env(t_build *b)
{
	t_build	nb;
	t_list2	*env_start;
	t_list2	*env_end;
	
	env_start = NULL;
	env_end = NULL;
	nb.env_start = &env_start;
	nb.env_end = &env_end;
	sh_env_check_kv(sh_env_check_flag(&b->args), b);
	if (*b->args)
	{
		nb.args = b->args;
		sh_process_cmd(*nb.env_start ? &nb : b);
	}
	else
		env_print(*nb.env_start ? *nb.env_start : *b->env_start);
}
