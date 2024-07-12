/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:32 by max               #+#    #+#             */
/*   Updated: 2024/07/12 05:07:37 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_variable_value(t_data *data)
{
	t_variable *current_var = data->variable;

	while (current_var)
	{
		if (current_var == NULL)
			printf("Empty variable node\n");
		else
			printf("variable value lst = %s\n", current_var->value);
		current_var = current_var->next;
	}
}

void print_test(t_tokens *lst)
{
	t_tokens *current = lst;
	while (current)
	{
		printf("Token adresse cleaned : %p\n", current);
		current = current->next;
	}
}
void print_test_two(t_tokens *lst)
{
	t_tokens *current = lst;
	while (current)
	{
		printf("Token adresse lst : %p\n", current);
		current = current->next;
	}
}

void print_cmd_table(t_data *data)
{
	t_commands_table *current_table = data->table;
	if (current_table == NULL)
		printf("Empty cmd table node\n");
	while (current_table)
	{
		printf("\n\nsimple cmd : %s\n", current_table->simple_cmd);
		printf("%s\n", current_table->syntaxe_error ? current_table->message_error : "syntaxe error = false");

		t_tokens *current_token = current_table->token;

		if (current_token == NULL)
			printf("Empty token node\n");
		else
		{
			while (current_token)
			{
				printf("Token: %s\n", current_token->word);
				current_token = current_token->next;
			}
		}

		current_table = current_table->next;
	}
}

void print_tokens(t_data *data)
{
	t_commands_table *current_table = data->table;

	while (current_table)
	{
		t_tokens *current_token = current_table->token;
		if (current_token == NULL)
		{
			printf("liste vide\n");
		}
		else
		{
			while (current_token)
			{
				printf("Token: %s\n", current_token->word);
				current_token = current_token->next;
			}
		}
		current_table = current_table->next;
	}
}