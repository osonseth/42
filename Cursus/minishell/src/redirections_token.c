/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:13:21 by max               #+#    #+#             */
/*   Updated: 2024/07/14 10:50:45 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void input_redirect_token(t_tokens **lst, t_data *data)
{
    char *tmp;

    tmp = ft_strdup("<");
    if (tmp == NULL)
    {
        data->table->token = data->new_lst;
        clean_token_lst_and_memory_error(*lst, data);
    }
    token_node_add_back(lst, new_token_node(tmp), data);
}

void output_redirect_token(t_tokens **lst, t_data *data)
{
    char *tmp;

    tmp = ft_strdup(">");
    if (tmp == NULL)
    {
        data->table->token = data->new_lst;
        clean_token_lst_and_memory_error(*lst, data);
    }
    token_node_add_back(lst, new_token_node(tmp), data);
}

void append_redirect_token(t_tokens **lst, int *i, t_data *data)
{
    char *tmp;

    tmp = ft_strdup(">>");
    if (tmp == NULL)
    {
        data->table->token = data->new_lst;
        clean_token_lst_and_memory_error(*lst, data);
    }
    token_node_add_back(lst, new_token_node(tmp), data);
    (*i)++;
}

void heredoc_token(t_tokens **lst, int *i, t_data *data)
{
    char *tmp;

    tmp = ft_strdup("<<");
    if (tmp == NULL)
    {
        data->table->token = data->new_lst;
        clean_token_lst_and_memory_error(*lst, data);
    }
    token_node_add_back(lst, new_token_node(tmp), data);
    (*i)++;
}

void create_normal_token(char *str, t_tokens **lst, int *i, t_data *data)
{
    char *tmp;

    tmp = ft_strdup_redir_token(str);
    if (tmp == NULL)
    {
        data->table->token = data->new_lst;
        clean_token_lst_and_memory_error(*lst, data);
    }
    token_node_add_back(lst, new_token_node(tmp), data);
    (*i) += (ft_strlen_redir_token(str) - 1);
}