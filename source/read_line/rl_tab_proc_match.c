#include "read_line.h"

static size_t	rl_t_get_max_len(const t_list *m)
{
	size_t	max;
	size_t	wtf;

	max = ft_strlen((char *)m->content);
	while (m->next)
	{
		wtf = ft_strlen((char *)m->next->content);
		if (wtf > max)
			max = wtf;
		m = m->next;
	}
	return (max);
}

static t_bool	rl_t_compare(const char *cmpr_str,
					const t_list *iter, size_t len)
{
	while (iter)
	{
		if (!ft_strnequ(cmpr_str, (char *)iter->content, len))
			return (true);
		iter = iter->next;
	}
	return (false);
}

static void		rl_t_end_move(const char *postfix, const t_list *m)
{
	if (*postfix)
	{
		ft_putstr(postfix);
		rl_join_str_to_line(postfix);
	}
	else
	{
		ft_putchar('\n');
		while (m)
		{
			ft_putendl((char *)m->content);
			m = m->next;
		}
		ft_putstr(sh()->prompt);
		ft_putstr(rl()->line);
	}
}

void			rl_t_process_matches(const t_list *m, size_t len)
{
	char			postfix[FILENAME_MAX + 1];
	size_t			elem_max_len;

	ft_bzero(postfix, FILENAME_MAX + 1);
	elem_max_len = rl_t_get_max_len(m);
	while (true)
	{
		if (++len > elem_max_len)
		{
			ft_strcat(postfix, " ");
			break ;
		}
		if ((rl_t_compare((char *)m->content, m->next, len)))
			break ;
		else
			ft_strncat(postfix, &((char *)m->content)[len - 1], 1);
	}
	rl_t_end_move(postfix, m);
}
