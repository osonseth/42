/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:08:22 by max               #+#    #+#             */
/*   Updated: 2024/07/07 23:23:57 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void recursive_handle_command_node(t_data *data, t_commands_table *table)
{

	if (table == NULL)
		return;

	if (expand_has_syntax_errors(table, data))
	{
		recursive_handle_command_node(data, table->next);
		return;
	}
	else
		node_tokenization(data, table);

	recursive_handle_command_node(data, table->next);
}

void parsing_management(t_data *data)
{
	if (pipe_syntax_errors(data))
		return;
	if (quote_syntax_errors(data))
		return;
	build_cmd_table(data);
	recursive_handle_command_node(data, data->table);
}