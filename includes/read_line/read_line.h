/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:12:06 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:12:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# include "shell.h"

# define UP (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define DOWN (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define RIGHT (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
# define LEFT (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)

# define WTF_UP (buf[0] == 27 && buf[1] == 91 && buf[2] == 72)
# define WTF_DOWN (buf[0] == 27 && buf[1] == 91 && buf[2] == 70)

# define TAB (buf[0] == 9)
# define BACK_SPACE (buf[0] == 127)
# define CTRL_D (buf[0] == 4)
# define NEW_LINE (buf[0] == 10)

typedef struct	s_line_syntax
{
	t_bool		semi_flag;
}				t_line_syntax;

typedef struct	s_read_line
{
	char		*line;
	size_t		len;
	size_t		i;
	t_bool		new_line_flag;
	t_bool		if_inhibitors_in_use_flag;
}				t_read_line;

enum
{
	RL_SEMIX1 = -2,
	RL_SEMIX2,
	RL_OK,
	RL_CONTINUE,
	RL_BREAK,
	RL_Q,
	RL_DQ,
	RL_SLASH
};

t_read_line		*rl(void);
void			rl_join_char_to_line(char c);
void			rl_join_str_to_line(char *str);

int32_t			rl_line_syntax(void);
int32_t			ls_backslash_check(t_line_syntax *ls);
int32_t			ls_dobule_q_check(t_line_syntax *ls);
int32_t			ls_single_q_check(t_line_syntax *ls);
int32_t			ls_semi_check(t_line_syntax *ls);

void			ls_print_info(int32_t key);
void			ls_check_for_unexpected_eof(int32_t key);

void			rl_back_space(void);
void			rl_ctrl_d(void);
int32_t			rl_new_line(void);
void			rl_tab(void);

void			rl_t_read_dir(t_list **m, char **paths, const char *bc);
void			rl_t_gm_push_cmd(t_list **m, const char *bc, const char *c);

#endif
