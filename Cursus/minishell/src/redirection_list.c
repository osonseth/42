/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:52:48 by max               #+#    #+#             */
/*   Updated: 2024/07/16 12:03:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirects *new_redirection_node(char *content, e_redirection_type type)
{
    t_redirects *node;

    node = malloc(sizeof(t_tokens));
    if (node == NULL)
    {
        free(content);
        return NULL;
    }
    node->content = content;
    node->type = type;
    node->next = NULL;
    return (node);
}
void redirection_node_add_back(t_redirects **lst, t_redirects *new, t_data *data)
{
    t_redirects *tmp;
    if (new == NULL)
        clean_redirection_lst_and_memory_error(*lst, data);
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

/* Crée la liste des redictions apartir de la liste des tokens
Met a jour un bool dans chaque noeud afin de savoir si le token faite partie d'une redirection ou pas
*/
t_redirects *create_redirection_lst(t_tokens **lst, t_data *data)
{
    bool(cmd_and_args) = false;
    t_redirects(*redirection_list) = NULL;
    t_tokens(*current) = *lst;

    while (current)
    {
        if (is_redirection_token(current->word))
        {
            cmd_and_args = false;
            redirection_list = create_redirection_node(current, redirection_list, data);
            current = current->next->next;
        }
        else if (cmd_and_args == false)
        {
            current->not_redir = true;
            cmd_and_args = true;
            current = current->next;
        }
        else
        {
            current->not_redir = true;
            current = current->next;
        }
    }
    return redirection_list;
}
