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

static void	msh_lp_loop(t_minishel *msh, t_line_parser *lp)
{
	const char *line;

	line = msh->line;
	while (*line)
	{
		
	}
}

static void	msh_lp_init(t_minishel *msh, t_line_parser *lp)
{
	ft_bzero(lp, sizeof(t_line_parser));
	if (!(lp->arg = ft_strdup("")))
		msh_error_exit(msh, MALLOC_ERR);
}

void		msh_line_parser(t_minishel *msh)
{
	t_line_parser lp;

	msh_lp_init(msh, &lp);
	msh_lp_loop(msh, &lp);
	msh_lp_free(msh, &lp);
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
