/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:32 by max               #+#    #+#             */
/*   Updated: 2024/07/15 23:53:55 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char *redirection_type_to_string(e_redirection_type type)
{
	switch (type)
	{
	case HEREDOC:
		return "HEREDOC";
	case OUTFILE:
		return "OUTFILE";
	case INFILE:
		return "INFILE";
	case APPEND:
		return "APPEND";
	default:
		return "UNKNOWN";
	}
}

//-----------------------------------------------------------

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

void print_array(char ** array)
{
	int i = 0;
	while (array[i])
	{
		printf("args[%d] = %s\n",i,array[i]);
		i++;
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
		t_redirects *redir = current_table->redirects;

		if (current_token == NULL)
			printf("Empty token node\n");
		if (redir == NULL)
			printf("Empty redirection node\n");
		printf("\n\n-------------------------------- TOKEN -----------------------------------------------\n\n");
		while (current_token)
		{
			printf("Token: %-15s  -> %d\n", current_token->word, current_token->not_redir);
			current_token = current_token->next;
		}
		printf("\n-------------------------------- ARRAY -----------------------------------------------\n");
		print_array(current_table->args);
		printf("\n---------------------------- REDIRECTIONS --------------------------------------------\n");
		while (redir)
		{
			printf("Type: %s, Content: %s\n", redirection_type_to_string(redir->type), redir->content);
			redir = redir->next;
		}
		printf("\n--------------------------------------------------------------------------------------\n");
		current_table = current_table->next;
	}
}

void print_lst (t_tokens *lst)
{
	t_tokens *current = lst;
	while (current)
	{
		if (current == NULL)
		{
			printf("liste vide\n");
		}
		else
		{
			printf("Token AVANT redirection tokenisation = %s\n",current->word);
		}
		current = current->next;
	}
}
void print_lst2 (t_tokens *lst)
{
	t_tokens *current = lst;
	while (current)
	{
		if (current == NULL)
		{
			printf("liste vide\n");
		}
		else
		{
			printf("Token APRES redirection tokenisation = %s\n",current->word);
		}
		current = current->next;
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
void print_env(char **env)
{
	int i = 0;
	printf("\n----------ENV-----------\n");
	while (env[i])
	{
		printf("%s\n",env[i]);
		i++;
	}
}

void print_all (t_data *data)
{
	print_cmd_table(data);
	// print_env(data->shell_env);
}