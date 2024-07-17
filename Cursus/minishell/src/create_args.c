/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:13:37 by max               #+#    #+#             */
/*   Updated: 2024/07/16 12:05:15 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Calcule la taille du char ** args 
*/

static int calculate_cmd_and_args(t_tokens *token)
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
/*
Crée le char ** args pour execve via la liste des tokens, si bool redirection = false alors l'ajoue dans le char **
*/

static char **fill_array(char **args, t_tokens *token, t_data *data)
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
/*
fonction pricipale pour créer le char ** args envoyé a execve
*/
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