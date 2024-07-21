/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:52:48 by max               #+#    #+#             */
/*   Updated: 2024/07/20 08:52:56 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirects *new_redirection_node(char *content, e_redirection_type type)
{
    t_redirects *node;
    if (content == NULL)
        return NULL;
    node = malloc(sizeof(t_redirects));
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
t_redirects *redirection_node_add_back(t_redirects *lst, t_redirects *new)
{
    t_redirects *tmp;
    if (new == NULL)
        return NULL;
    if (!lst)
    {
        lst = new;
        return lst;
    }
    tmp = lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return lst;
}

/* Crée la liste des redictions apartir de la liste des tokens
Met a jour un bool dans chaque noeud afin de savoir si le token faite partie d'une redirection ou pas
*/

bool create_redirection_lst(t_tokens *lst, t_redirects **redirection_list)
{
    t_tokens(*current) = lst;
    t_redirects(*save_lst) = NULL;

    while (current)
    {
        if (is_redirection_token(current->word))
        {
            *redirection_list = create_redirection_node(current, *redirection_list);
            current = current->next->next;
        }
        else
        {
            current->not_redir = true;
            current = current->next;
            continue;
        }
        if (!*redirection_list)
        {
            clean_redirection_lst(save_lst);
            return false;
        }
        save_lst = *redirection_list;
    }
    return true;
}
