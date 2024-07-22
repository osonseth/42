/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:20 by max               #+#    #+#             */
/*   Updated: 2024/07/21 23:50:23 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_variable_lst(t_data *data)
{
    t_variable *current;
    t_variable *next;

    if (data == NULL || data->variable == NULL)
        return;

    current = data->variable;

    while (current != NULL)
    {
        next = current->next;  
        free(current); 
        current = next; 
    }

    data->variable = NULL; 
}


void clean_redirection_lst(t_redirects *lst)
{
    if (lst == NULL)
        return;
    t_redirects *next_lst;
    next_lst = lst->next;
    if (lst)
    {

        if (lst->content)
            free(lst->content);
        free(lst);
    }
    lst = next_lst;
    clean_redirection_lst(lst);
}

void clean_token_lst(t_tokens **lst)
{
    if (*lst == NULL)
        return;
    t_tokens *next_lst;
    next_lst = (*lst)->next;
    if (*lst)
    {
        if ((*lst)->word)
        {
            free((*lst)->word);
            (*lst)->word = NULL;
        }
        free(*lst);
        *lst = NULL;
    }
    *lst = next_lst;
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
            clean_token_lst(&data->table->token);
        if (data->table->redirects)
            clean_redirection_lst(data->table->redirects);
        if (data->table->simple_cmd)
            free(data->table->simple_cmd);
        if (data->table->message_error)
            free(data->table->message_error);
        if (data->table->args)
            clean_args(data->table->args);
        free(data->table);
    }
    data->table = ptr_next;
    clean_cmd_table(data);
}

void clean_all(t_data *data)
{
    if (data->line)
        free(data->line);
    if (data->variable)
        clean_variable_lst(data);
    if (data->table)
        clean_cmd_table(data);

}
