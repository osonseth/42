/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:20 by max               #+#    #+#             */
/*   Updated: 2024/07/15 00:07:29 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void clean_variable_lst(t_variable *lst)
{
    if (lst == NULL)
        return;
    t_variable *next_lst;
    next_lst = lst->next;
    if (lst)
        free(lst);
    lst = next_lst;
    clean_variable_lst(lst);
}
void clean_redirection_lst(t_redirects *lst)
{
    if (lst == NULL)
        return;
    t_redirects *next_lst;
    next_lst = lst->next;
    if (lst)
    {
        printf("content redir to clean = %s\n", lst->content);
        if (lst->content)
            free(lst->content);
        free(lst);
    }
    lst = next_lst;
    clean_redirection_lst(lst);
}

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
        if (data->table->redirects)
            clean_redirection_lst(data->table->redirects);
        if (data->table->simple_cmd)
            free(data->table->simple_cmd);
        if (data->table->message_error)
            free(data->table->message_error);
        if (data->table->args)
            clean_array(data->table->args);
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
        clean_variable_lst(data->variable);
    if (data->old_lst)
        clean_token_lst(data->old_lst);
    if (data->table)
        clean_cmd_table(data);
}
