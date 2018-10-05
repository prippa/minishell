/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:33:54 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:33:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MSH_NAME			"minishell"

# define MSH_P_ICON			"➥"
# define MSH_ERR			"ERROR: " MSH_NAME ": %s\n"

# define MSH_EXIT			"exit"

# define MSH_GETCWD_ERR		"getcwd failed"

# define MSH_SETENV_USG		"Usage: setenv [name=arg] ...\n"

# define MSH_UNSETENV_USG		"Usage: unsetenv [name] ...\n"
# define MSH_UNSETENV_NO_NAME	"unsetenv: '%s' not found.\n"

#endif
