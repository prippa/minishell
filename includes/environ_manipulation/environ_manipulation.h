/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_manipulation.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:53:20 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 13:53:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_MANIPULATION_H
# define ENVIRON_MANIPULATION_H

# include "libft.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

# define ENV(k, v) &(t_env){.key = k, .value = v}

void			env_del_body(t_env *e);
void			env_del_list(void *content, size_t content_size);

t_list2			*env_get_obj_by_key(t_list2 *env_start, const char *key);
char			*env_get_vlu_by_key(t_list2 *env_start, const char *key);
int32_t			env_set(t_list2 **env_start, t_list2 **env_end,
					const t_env *new_env, t_bool overwrite);
int32_t			env_unset(t_list2 **env_start, t_list2 **env_end,
					const char *key);
void			env_print(t_list2 *env_start);
char			**env_convert_to_arr(t_list2 *env_start);
t_env			env_make_clone_of_body(const t_env *origin);

#endif
