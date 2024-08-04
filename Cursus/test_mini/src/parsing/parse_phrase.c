/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_phrase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:24:59 by junsan            #+#    #+#             */
/*   Updated: 2024/07/26 13:20:28 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_phrase(t_token **token, t_ast **node)
{
	t_ast	*subshell_node;

	subshell_node = NULL;
	if (*token && (*token)->type == SUBSHELL)
		parse_subshell(token, &subshell_node);
	if (subshell_node)
		*node = subshell_node;
	if (*token && (*token)->type == REDIRECTION)
	{
		if (!parse_phrase_part(\
				token, node, parse_redirection_part))
			return (false);
	}
	else if (*token && (*token)->type == CMD)
	{
		if (!parse_phrase_part(token, node, parse_cmd_part))
			return (false);
	}
	return (true);
}
