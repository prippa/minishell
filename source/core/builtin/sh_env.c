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
#include "messages.h"

#define ENV_I_F				"-i"
#define ENV_PREFIX			ENV_CMD ": "
#define ENV_INVALID_ARG		ENV_PREFIX "setenv %s: Invalid argument"

static t_bool	sh_env_check_kv(t_bool i_flag, t_build *nb, t_build *b)
{
	if (!i_flag)
		env_make_clone(nb->env_start, nb->env_end, *b->env_start);
	while (*b->args)
	{
		if (**b->args == KEY_VALUE_SEPARATOR)
		{
			PRINT_ERR(EXIT_FAILURE, ENV_INVALID_ARG, *b->args);
			return (false);
		}
		if (ft_strchr(*b->args, KEY_VALUE_SEPARATOR))
			sh_setenv_one_env(nb->env_start, nb->env_end, *b->args, false);
		else
			break ;
		++b->args;
	}
	return (true);
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
	if (sh_env_check_kv(sh_env_check_flag(&b->args), &nb, b))
	{
		if (*b->args)
		{
			nb.args = b->args;
			sh_process_cmd(&nb, ENV_PREFIX);
		}
		else
			env_print(*nb.env_start);
	}
	ft_lst2del(nb.env_start, nb.env_end, env_del_list);
}
