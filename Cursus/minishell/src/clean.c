/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:20 by max               #+#    #+#             */
/*   Updated: 2024/07/06 16:11:20 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_token_lst(t_tokens *lst)
{
    if (lst == NULL)
        return;
    t_tokens *next_lst;
    next_lst = lst->next;
    if (lst)
    {
        if (lst->word)
            free(lst->word);
        free(lst);
    }
    lst = next_lst;
    clean_token_lst(lst);
}
void clean_cmd_table(t_data *data)
{
    if (data->table == NULL)
        return;
    t_commands_table *ptr_next;
    ptr_next = data->table->next;

    if (data->table)
    {
        if (data->table->token)
            clean_token_lst(data->table->token);
        if (data->table->simple_cmd)
            free(data->table->simple_cmd);
        if (data->table->message_error)
            free(data->table->message_error);
        free(data->table);
    }
    data->table = ptr_next;
    clean_cmd_table(data);
}

void clean_all(t_data *data)
{
    if (data->line)
        free(data->line);
    if (data->table)
        clean_cmd_table(data);
}
