/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:41:21 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 16:41:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	fpf_conv_sig_int(t_printf *fpf)
{
	intmax_t num;

	if (fpf->size_flag == SF_HH)
		num = (signed char)va_arg(fpf->args, intmax_t);
	else if (fpf->size_flag == SF_H)
		num = (signed short)va_arg(fpf->args, intmax_t);
	else if (fpf->size_flag == SF_L)
		num = (signed long)va_arg(fpf->args, intmax_t);
	else if (fpf->size_flag == SF_LL)
		num = (signed long long)va_arg(fpf->args, intmax_t);
	else if (fpf->size_flag == SF_J)
		num = (intmax_t)va_arg(fpf->args, intmax_t);
	else if (fpf->size_flag == SF_Z)
		num = (size_t)va_arg(fpf->args, intmax_t);
	else
		num = (signed int)va_arg(fpf->args, intmax_t);
	return (num);
}

uintmax_t	fpf_conv_unsig_int(t_printf *fpf)
{
	uintmax_t num;

	if (fpf->size_flag == SF_HH)
		num = (unsigned char)va_arg(fpf->args, uintmax_t);
	else if (fpf->size_flag == SF_H)
		num = (unsigned short)va_arg(fpf->args, uintmax_t);
	else if (fpf->size_flag == SF_L)
		num = (unsigned long)va_arg(fpf->args, uintmax_t);
	else if (fpf->size_flag == SF_LL)
		num = (unsigned long long)va_arg(fpf->args, uintmax_t);
	else if (fpf->size_flag == SF_J)
		num = (uintmax_t)va_arg(fpf->args, uintmax_t);
	else if (fpf->size_flag == SF_Z)
		num = (size_t)va_arg(fpf->args, uintmax_t);
	else
		num = (unsigned int)va_arg(fpf->args, uintmax_t);
	return (num);
}
