/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_line_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:41:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:41:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

static void	msh_line_parser_loop(t_msh *msh, t_line_parser *prs)
{
	const char *line;

	line = msh->line;
	while (*line)
	{
		
	}
}

void		msh_line_parser(t_msh *msh)
{
	t_line_parser prs;

	ft_bzero(&prs, sizeof(t_line_parser));
	if (!(prs.arg = ft_strdup("")))
		msh_error_exit(msh, MALLOC_ERR);
	msh_line_parser_loop(msh, &prs);
	// char	**arr;
	// size_t	i;
	// t_list2	*start;

	// i = -1;
	// arr = (char **)malloc(sizeof(char *) * msh->env_size + 1);
	// start = msh->env_start;
	// while (++i < msh->env_size)
	// {
	// 	arr[i] = ((t_env *)start->content)->value;
	// 	start = start->next;
	// }
	// arr[i] = NULL;
	// ft_putarr(arr);
	// free(arr);
	// ft_printf("%s\n", msh->line);
}
