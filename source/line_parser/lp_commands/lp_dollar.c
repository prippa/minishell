/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:54 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "environ_manipulation.h"

static void	lp_dollar_write(t_line_parser *lp, char *s, size_t len)
{
	char *key;

	GET_MEM(MALLOC_ERR, key, ft_strsub, s, 0, len);
	if ((s = env_get_vlu_by_key(sh()->env_start, key)))
		lp_write_to_arg_buf_str(lp, s, ft_strlen(s));
	ft_memdel((void **)&key);
}

void		lp_dollar(t_line_parser *lp)
{
	char	*s;
	size_t	len;

	if (!ft_isalnum_in_case(sh()->line[sh()->i + 1]))
	{
		lp_write_to_arg_buf_char(lp, sh()->line[sh()->i]);
		return ;
	}
	s = &sh()->line[++sh()->i];
	if (ft_isalpha_in_case(sh()->line[sh()->i]))
	{
		len = 1;
		while (ft_isalnum_in_case(sh()->line[++sh()->i]))
			++len;
		lp_dollar_write(lp, s, len);
		--sh()->i;
	}
}
