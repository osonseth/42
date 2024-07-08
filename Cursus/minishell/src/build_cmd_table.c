/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:07:48 by max               #+#    #+#             */
/*   Updated: 2024/07/04 23:53:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void cmd_table_node_add_back(t_commands_table **lst, t_commands_table *new, t_data *data)
{
    t_commands_table *tmp;
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

void build_cmd_table(t_data *data)
{
    int i;
    i = 0;
    char *line_start;
    line_start = data->line;
    while (data->line[i] != '\0')
    {
        if (data->line[i] == '|')
        {
            line_start = ft_strdup_simple_cmd(line_start);
            if (line_start == NULL)
                memory_error(data);
            cmd_table_node_add_back(&(data->table), new_cmd_table_node(line_start), data);
            line_start = &data->line[i + 1];
        }
        else if (data->line[i + 1] == '\0')
        {
            line_start = ft_strdup_simple_cmd(line_start);
            if (line_start == NULL)
                memory_error(data);
            cmd_table_node_add_back(&(data->table), new_cmd_table_node(line_start), data);
        }
        i++;
    }
}
