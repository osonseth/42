/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:24:16 by max               #+#    #+#             */
/*   Updated: 2024/07/21 09:44:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable *new_variable_node(void *content)
{

    t_variable *node;

    node = malloc(sizeof(t_variable));
    if (node == NULL)
        return NULL;
    node->value = content;
    node->next = NULL;
    return (node);
}

bool variable_node_add_back(t_variable **lst, t_variable *new)
{
    t_variable *tmp;
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