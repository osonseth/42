/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:08:22 by max               #+#    #+#             */
/*   Updated: 2024/07/16 00:10:58 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int calculate_cmd_and_args(t_tokens *token)
{

	t_tokens *current;
	int nbr;

	nbr = 0;
	current = token;

	while (current)
	{
		if (current->not_redir)
			nbr++;
		current = current->next;
	}
	return nbr;
}

char **fill_array(char **args, t_tokens *token, t_data *data)
{
	int i;
	t_tokens *current;

	current = token;
	i = 0;

	while (current)
	{
		if (current->not_redir == true)
		{
			args[i] = ft_strdup(current->word);
			if (!args[i])
			{
				clean_array(args);
				memory_error(data);
			}
			i++;
		}
		current = current->next;
	}
	return args;
}

char **create_args_array(t_commands_table *table, t_data *data)
{

	char **args;
	int number_of_args;
	int i;

	i = 0;
	number_of_args = calculate_cmd_and_args(table->token);
	args = malloc((number_of_args + 1) * sizeof(char *));
	if (!args)
		return NULL;
	while (i <= number_of_args)
		args[i++] = NULL;
	args = fill_array(args, table->token, data);
	return args;
}

//----------------------------------------------------------------------------------------------

void recursive_handle_expand_token(t_tokens *token, t_data *data)
{
	if (token == NULL)
		return;
	token->word = expand_management(token->word, data);
	token->word = remove_unnecessary_quotes(token->word, data);
	clean_variable_lst(data->variable);
	data->variable = NULL;
	recursive_handle_expand_token(token->next, data);
}

bool recursive_handle_command_node(t_data *data, t_commands_table *table)
{
	if (table == NULL)
		return false;

	if (expand_has_syntax_errors(table, data) || table->syntaxe_error)
	{
		recursive_handle_command_node(data, table->next);
		return false;
	}
	node_tokenization(data, table);
	print_lst(table->token);
	
	redir_tokenization(&(table->token), data);
	recursive_handle_expand_token(table->token, data);
	printf("\n-------------------------------------------------------------------------\n");
	print_lst2(table->token);
	if (redirection_syntax_errors(table->token))
		return true;
	table->redirects = create_redirection_lst(&(table->token), data);
	table->args = create_args_array(table, data);
	if (!table->args)
		memory_error(data);
	return (recursive_handle_command_node(data, table->next));
}

bool parsing_management(t_data *data)
{
	quotes_reset(data);
	if (pipe_syntax_errors(data))
		return false;
	if (quote_syntax_errors(data))
		return false;
	build_cmd_table(data);
	if (recursive_handle_command_node(data, data->table))
		return false;
	return true;
}