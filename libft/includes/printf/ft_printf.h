/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:11 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define FPF_BUF_SIZE 1024

typedef enum	e_fpf_size_flags
{
	SF_H = 1,
	SF_HH,
	SF_L,
	SF_LL,
	SF_J,
	SF_Z
}				t_fpf_size_flags;

typedef enum	e_fpf_flags
{
	F_MINUS,
	F_PLUS,
	F_SPACE,
	F_SHARP,
	F_ZERO,
	F_DOT,
	F_COLOR,
	F_UPERCASE,
	FLAG_SIZE
}				t_fpf_flags;

typedef struct	s_printf
{
	va_list		args;
	const char	*format;
	char		*str;
	int32_t		fd;
	char		buf[FPF_BUF_SIZE + 1];
	int32_t		buflen;
	char		f[FLAG_SIZE];
	int32_t		color;
	int32_t		width;
	int32_t		precision;
	int32_t		size_flag;
	char		type;
	int32_t		len;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
void			fpf_cat_char(t_printf *fpf, char c);
void			fpf_cat_str(t_printf *fpf, const char *src);
void			fpf_cat_char_len(t_printf *fpf, int32_t n, char c);
void			fpf_cat_str_len(t_printf *fpf, const char *src, int32_t n);
void			fpf_parser(t_printf *fpf);
intmax_t		fpf_conv_sig_int(t_printf *fpf);
uintmax_t		fpf_conv_unsig_int(t_printf *fpf);
void			fpf_malloc_error_exit(void);
void			fpf_get_type(t_printf *fpf);
char			*fpf_wstr_to_str(wchar_t *ws);
void			fpf_init_random_char(t_printf *fpf);
void			fpf_output_c(t_printf *fpf);
void			fpf_output_d(t_printf *fpf);
void			fpf_output_ox(t_printf *fpf);
void			fpf_output_p(t_printf *fpf);
void			fpf_output_s(t_printf *fpf);
void			fpf_output_u(t_printf *fpf);
void			fpf_set_color(t_printf *fpf);
void			fpf_before_processing_data(t_printf *fpf);
void			fpf_after_processing_data(t_printf *fpf);

#endif
