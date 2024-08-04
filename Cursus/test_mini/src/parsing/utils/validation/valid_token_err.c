/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_token_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:14:53 by junsan            #+#    #+#             */
/*   Updated: 2024/08/01 11:09:34 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_redir_err(t_token *prev, t_token *cur, t_token *next)
{
	(void)prev;
	if (cur->data[0] == '<' || cur->data[0] == '>')
	{
		if (get_type_redir(cur->data) == NOT_REDIR)
			return (true);
		if (!next || is_operator(next->data) || \
			is_redirection_operator(next->data))
			return (true);
	}
	return (false);
}

bool	check_redir_err(t_token *head)
{
	t_token	*prev;
	t_token	*next;
	t_token	*cur;

	cur = head;
	prev = cur;
	while (cur)
	{
		next = cur->next;
		if (is_redir_err(prev, cur, next))
			return (true);
		prev = cur;
		cur = cur->next;
	}
	if (prev && get_type_redir(prev->data) != NOT_REDIR)
		return (true);
	return (false);
}

static bool	is_operator_err(t_token *prev, t_token *cur, t_token *next)
{
	(void)prev;
	if (is_operator(cur->data))
	{
		if (!prev)
			return (true);
		if (!next)
			return (true);
	}
	return (false);
}

bool	check_operator_before_after_err(t_token *head)
{
	t_token	*prev;
	t_token	*next;
	t_token	*cur;

	cur = head;
	prev = cur;
	if (cur && is_operator(cur->data))
		return (true);
	while (cur)
	{
		next = cur->next;
		if (is_operator_err(prev, cur, next))
			return (true);
		prev = cur;
		cur = cur->next;
	}
	if (prev && is_operator(prev->data))
		return (true);
	return (false);
}

bool	check_subshell_err(t_token *head)
{
	t_token	*cur;
	bool	found_redir;

	found_redir = false;
	cur = head;
	while (cur)
	{
		if (get_type(cur->data) == REDIRECTION)
			found_redir = true;
		if (get_type(cur->data) == SUBSHELL && cur->data[0] == '(')
		{
			if (found_redir)
				return (true);
		}
		if (get_type(cur->data) == LOGICAL || get_type(cur->data) == PIPE)
			found_redir = false;
		cur = cur->next;
	}
	return (false);
}
