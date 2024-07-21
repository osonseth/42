/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:07:48 by max               #+#    #+#             */
/*   Updated: 2024/07/18 19:14:09 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Initialise les champs du noeud de la table des commande :
syntaxe_error -> true = erreur de syntaxe dans la commande simple
message_error -> message a print si la commande simple contient une erreur de syntaxe
simple_cmd    -> char * contenant la commande simple
args          -> char ** devant etre passer a execve contenant le nom du programme et ses arguments
token         -> liste de la commande simple tokenisé
redirects     -> liste des redirections de la commande simple dans l'ordre
next          -> pointeur vers le noeud suivant
*/
static void initialize_node(t_commands_table *node, void *content)
{
    node->syntaxe_error = false;
    node->message_error = NULL;
    node->simple_cmd = content;
    node->args = NULL;
    node->token = NULL;
    node->redirects = NULL;
    node->next = NULL;
}
/*
Ajout des nouveaux neud a la fin de la liste
*/
bool cmd_table_node_add_back(t_commands_table **lst, t_commands_table *new)
{
    t_commands_table *tmp;
    if (new == NULL)
        return false;
    if (!*lst)
    {
        *lst = new;
        return true;
    }
    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return true;
}
/*
Creation des noeuds de la table des commandes
*/

t_commands_table *new_cmd_table_node(void *content)
{
    t_commands_table *node;

    node = malloc(sizeof(t_commands_table));
    if (node == NULL)
    {
        if (content)
            free(content);
        return NULL;
    }
    initialize_node(node, content);
    return (node);
}

/*
Creation d'1 noeud par commande  simple a chaque '|' hors quote trouvé ou a la fin de la string
Pointeur line start qui se deplace a chaque '|' char +1 pour dup
Creation de chaque noeud avec node add back et new node
*/
bool build_cmd_table(t_data *data)
{ 
    int i;
    i = 0;

    char *line_start;
    line_start = data->line;
    while (data->line[i] != '\0')
    {
        opening_and_closing_quotes(data->line[i], data);
        if ((data->line[i] == '|' && !data->double_quote && !data->simple_quote) || data->line[i + 1] == '\0')
        {
            line_start = ft_strdup_simple_cmd(line_start, data);
            if (line_start == NULL || !cmd_table_node_add_back(&(data->table), new_cmd_table_node(line_start)))
               return false;
            line_start = &data->line[i + 1];
        }
        i++;
    }
    return true;
}
