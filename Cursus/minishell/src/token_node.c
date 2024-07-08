/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:07:12 by max               #+#    #+#             */
/*   Updated: 2024/07/08 08:32:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens *new_token_node(void *content)
{

    t_tokens *node;

    node = malloc(sizeof(t_tokens));
    if (node == NULL)
        return NULL;
    node->word = content;
    node->next = NULL;
    return (node);
}

void token_node_add_back(t_tokens **lst, t_tokens *new, t_data *data)
{
    t_tokens *tmp;
    if (new == NULL)
        memory_error(data);
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
