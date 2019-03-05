/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		sh_init(void)
{
	ft_bzero(sh(), sizeof(t_shell));
	sh_init_env();
	sh()->ok = true;
	sh_update_curent_dir_name();
	sh_update_prompt(true);
	signal(SIGINT, sh_handle_sigint_base);
}
