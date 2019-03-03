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
#include "environ_manipulation.h"

#define ENV_I_F		"-i"

static void		sh_env_check_kv(t_bool i_flag,
					t_list2 *env_start, t_list2 *env_end, char ***args)
{
	
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

void			sh_env(char **args)
{
	t_list2	*env_start;
	t_list2	*env_end;

	env_start = NULL;
	env_end = NULL;
	sh_env_check_kv(sh_env_check_flag(&args), env_start, env_end, &args);
	if (*args)
	{
		if (env_start)
			sh_process_cmd(&env_start, &env_end, args);
		else
			sh_process_cmd(&g_sh.env_start, &g_sh.env_end, args);
	}
	else
		env_print(g_sh.env_start);
}
