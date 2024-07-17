/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:08:22 by max               #+#    #+#             */
/*   Updated: 2024/07/17 12:39:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*		Recursivité sur chaque noeud de la table des commandes pour parsing

expand has syntax errors		: check les erreurs de syntaxe sur les variable d'env
node tokenization				: tokenise la cmd via espace hors quote
redir tokenization				: tokenise les précédents token via redirection hors quote
recursive hanlde expand token	: recursivité sur les tokens pour expand les variable d'env
redirection syntax errors		: check les redirections sans nom de fichier ou d'EOF
create redirection lst			: crée la liste des redirections a partir des tokens
create args array				: crée le char ** a passer a execve

*/
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
	redir_tokenization(&(table->token), data);
	recursive_handle_expand_token(table->token, data);
	if (redirection_syntax_errors(table->token))
		return true;
	table->redirects = create_redirection_lst(&(table->token), data);
	table->args = create_args_array(table, data);
	if (!table->args)
		memory_error(data);
	return (recursive_handle_command_node(data, table->next));
}
/*
 pipe syntax errors  		: check les erreurs de syntaxe (pipe en debut de cmd, pipe en fin de cmd, 2 pipe se suivant sans rien entre)
 quote syntax errors 		: check les quotes non fermées
 build cmd table	 		: construction de la table des cmd, divisant la cmd entiere en cmd simple (+ 1 noeud par pipe)
 recursive handle cmd node  : recursivité sur chaque noeud de la table des commandes pour parsing
*/
bool parsing_management(t_data *data)
{
	if (pipe_syntax_errors(data))
		return false;
	if (quote_syntax_errors(data))
		return false;
	build_cmd_table(data);
	if (recursive_handle_command_node(data, data->table))
		return false;
	return true;
}