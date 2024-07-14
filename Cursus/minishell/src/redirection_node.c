/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:13:32 by max               #+#    #+#             */
/*   Updated: 2024/07/14 10:46:31 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void heredoc_node(t_tokens *token, t_redirects **lst, t_data *data)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        clean_redirection_lst_and_memory_error(*lst, data);
    redirection_node_add_back(lst, new_redirection_node(content, HEREDOC), data);
}
static void append_node(t_tokens *token, t_redirects **lst, t_data *data)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        clean_redirection_lst_and_memory_error(*lst, data);
    redirection_node_add_back(lst, new_redirection_node(content, APPEND), data);
}
static void outfile_node(t_tokens *token, t_redirects **lst, t_data *data)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        clean_redirection_lst_and_memory_error(*lst, data);
    redirection_node_add_back(lst, new_redirection_node(content, OUTFILE), data);
}
static void infile_node(t_tokens *token, t_redirects **lst, t_data *data)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        clean_redirection_lst_and_memory_error(*lst, data);
    redirection_node_add_back(lst, new_redirection_node(content, INFILE), data);
}

t_redirects *create_redirection_node(t_tokens *token, t_redirects *lst, t_data *data)
{
    if (!ft_strncmp(token->word, "<<", 2))
        heredoc_node(token, &lst, data);
    else if (!ft_strncmp(token->word, ">>", 2))
        append_node(token, &lst, data);
    else if (!ft_strncmp(token->word, "<", 1))
        infile_node(token, &lst, data);
    else if (!ft_strncmp(token->word, ">", 1))
        outfile_node(token, &lst, data);
    return lst;
}