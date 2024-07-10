/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:24:16 by max               #+#    #+#             */
/*   Updated: 2024/07/10 02:26:50 by max              ###   ########.fr       */
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

void variable_node_add_back(t_variable **lst, t_variable *new, t_data *data)
{
    t_variable *tmp;
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