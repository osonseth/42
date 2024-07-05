/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:20 by max               #+#    #+#             */
/*   Updated: 2024/07/04 18:40:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_all(t_data *data)
{
    if (data->line)
        free(data->line);
    if (data->table)
        clean_cmd_table(data);
}

void clean_cmd_table(t_data *data)
{
    if (data->table == NULL)
        return;
    t_commands_table *ptr_next;
    ptr_next = data->table->next;

    if (data->table)
    {
        if (data->table->simple_cmd)
            free(data->table->simple_cmd);
        if (data->table->message_error)
            free(data->table->message_error);
        free(data->table);
    }
    data->table = ptr_next;
    clean_cmd_table(data);
}
