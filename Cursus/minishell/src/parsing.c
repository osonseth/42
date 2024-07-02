/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:08:22 by max               #+#    #+#             */
/*   Updated: 2024/07/03 00:58:38 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool next_node_is_empty(char *str)
{
	while (*str && *str != '|')
	{
		if (!(*str == 32 || *str == 9))
			return true;
		str++;
	}
	return false;
}

void check_pipe(t_data *data)
{
	char *str;
	str = skype_space_ptr(data->line);
	if (*str == '|')
		print_syntax_error(data, PIPE);
	while (*str)
	{
		if (*str == '|')
		{
			if (!(next_node_is_empty(&str[1])))
				print_syntax_error(data, PIPE);
		}
		str++;
	}
}

void recursive_handle_command_node(t_data *data, t_commands_table *table)
{

	if (table == NULL)
		return;
	// implémenté les fonctions qui gere les commandes simples
	// fonction1(table);
	// fonction2(table);
	// fonction3(table);
	recursive_handle_command_node(data, table->next);
}

void parsing_management(t_data *data)
{
	check_pipe(data);
	check_quote(data);
	recursive_handle_command_node(data,data->table);
	build_cmd_table(data);
}