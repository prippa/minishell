/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:14:36 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 18:14:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_put.h"
#include <stdlib.h>

void	fpf_init_random_char(t_printf *fpf)
{
	if (!(fpf->str = (char *)malloc(sizeof(char) * 2)))
		fpf_malloc_error_exit();
	fpf->str[0] = *fpf->format;
	fpf->str[1] = 0;
	fpf->type = 'c';
	++fpf->format;
}

void	fpf_malloc_error_exit(void)
{
	ft_putendl_fd("ERROR: malloc failed", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
