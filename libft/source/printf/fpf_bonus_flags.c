/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_bonus_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:33:16 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:33:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_to.h"
#include "ft_color.h"

void		fpf_before_processing_data(t_printf *fpf)
{
	if (fpf->f[F_COLOR])
		fpf_set_color(fpf);
	if (fpf->f[F_UPERCASE])
		ft_to_str_upper(&fpf->str);
}

void		fpf_after_processing_data(t_printf *fpf)
{
	if (fpf->f[F_COLOR])
		fpf_cat_str(fpf, COLOR_RESET);
}
