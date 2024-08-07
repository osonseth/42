/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:07:12 by max               #+#    #+#             */
/*   Updated: 2024/07/19 00:47:30 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool token_lst_add_back(t_tokens **new_lst, t_tokens *lst)
{
    if (lst == NULL)
        return false;
    if (*new_lst == NULL)
    {
        *new_lst = lst;
        return true;
    }
    t_tokens *temp = *new_lst;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = lst;
    return true;
}
t_tokens *new_token_node(void *content)
{
    if(content == NULL)
        return NULL;
    t_tokens *node;

    node = malloc(sizeof(t_tokens));
    if (node == NULL)
        return NULL;
    node->word = content;
    node->not_redir = false;
    node->next = NULL;
    return (node);
}

bool token_node_add_back(t_tokens **lst, t_tokens *new)
{
    t_tokens *tmp;
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
//-------------------------------------------------------------------------------------

