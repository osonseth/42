/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:13:32 by max               #+#    #+#             */
/*   Updated: 2024/07/20 08:47:59 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redirects *heredoc_node(t_tokens *token, t_redirects *lst)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        return NULL;
    lst = redirection_node_add_back(lst, new_redirection_node(content, HEREDOC));
    if (!lst)
        return NULL;
    return lst;
}
static t_redirects *append_node(t_tokens *token, t_redirects *lst)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        return NULL;
    lst = redirection_node_add_back(lst, new_redirection_node(content, APPEND));
    if (!lst)
        return NULL;
    return lst;
}
static t_redirects *outfile_node(t_tokens *token, t_redirects *lst)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        return NULL;
    lst = redirection_node_add_back(lst, new_redirection_node(content, OUTFILE));
    if (!lst)
        return NULL;
    return lst;
}
static t_redirects *infile_node(t_tokens *token, t_redirects *lst)
{
    char *content;
    content = ft_strdup(token->next->word);
    if (!content)
        return NULL;
    lst = redirection_node_add_back(lst, new_redirection_node(content, INFILE));
    if (!lst)
        return NULL;
    return lst;
}

t_redirects *create_redirection_node(t_tokens *token, t_redirects *lst)
{
  
    if (!ft_strncmp(token->word, "<<", 2))
        lst = heredoc_node(token, lst);
    else if (!ft_strncmp(token->word, ">>", 2))
        lst = append_node(token, lst);
    else if (!ft_strncmp(token->word, "<", 1))
        lst = infile_node(token, lst);
    else if (!ft_strncmp(token->word, ">", 1))
        lst = outfile_node(token, lst);

    print_lst(lst);

    if (!lst)
        return NULL;

    return lst;
}
