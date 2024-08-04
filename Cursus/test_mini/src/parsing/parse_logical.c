/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_logical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:23:45 by junsan            #+#    #+#             */
/*   Updated: 2024/07/29 18:29:19 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_logical(t_token **token, t_ast **node)
{
	t_ast	*logical_node;
	t_ast	*left;

	left = NULL;
	if (*token && (*token)->type == SUBSHELL)
	{
		if (!parse_subshell(token, node))
			return (false);
	}
	else if (!parse_pipe(token, node))
		return (false);
	while (*token && (*token)->type == LOGICAL)
	{
		logical_node = new_node((*token)->data, (*token)->type);
		if (!logical_node)
			return (false);
		*token = (*token)->next;
		if (!parse_pipe(token, &left))
			return (free(logical_node), false);
		logical_node->left = left;
		logical_node->right = *node;
		add_parent(logical_node, logical_node->left, logical_node->right);
		*node = logical_node;
	}
	return (true);
}
