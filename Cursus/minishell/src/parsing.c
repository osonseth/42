/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:08:22 by max               #+#    #+#             */
/*   Updated: 2024/07/03 23:34:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void node_tokenization(t_commands_table *table)
// {

// }

void recursive_handle_command_node(t_data *data, t_commands_table *table)
{

	if (table == NULL)
		return;

	if (expand_syntax_error(table, data))
	{
		recursive_handle_command_node(data, table->next);
		return;
	}
	else

		printf("\n\nRien ici pour le moment\n\n");
	//{
	// node_tokenization(table);

	// implémenté les fonctions qui gere les commandes simples
	// fonction1(table);
	// fonction2(table);
	// fonction3(table);
	//}
	recursive_handle_command_node(data, table->next);
}

void parsing_management(t_data *data)
{
	check_pipe(data);
	check_quote(data);
	build_cmd_table(data);
	recursive_handle_command_node(data, data->table);
}