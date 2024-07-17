/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:11:03 by max               #+#    #+#             */
/*   Updated: 2024/07/16 12:01:30 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 bool is_redirection_token(char *word)
{
    return (!ft_strncmp(word, "<<", 2) || !ft_strncmp(word, ">>", 2) || !ft_strncmp(word, "<", 1) || !ft_strncmp(word, ">", 1));
}
int redirection_type(char *word)
{
    if (!ft_strncmp(word, "<<", 2))
        return HEREDOC;
    else if (!ft_strncmp(word, ">>", 2))
        return APPEND;
    else if (!ft_strncmp(word, "<", 2))
        return INFILE;
    else if (!ft_strncmp(word, ">", 2))
        return OUTFILE;
    return false;
}
/*
Check les redirections sans fichiers ou EOF pour les heredoc
*/

int redirection_syntax_errors(t_tokens *token)
{
    t_tokens *current;
    current = token;

    while (current)
    {
        if (current->next == NULL && is_redirection_token(current->word))
        {
            print_syntax_error(redirection_type(current->word));
            return true;
        }
        if (current->next != NULL)
        {
            if (is_redirection_token(current->word) && is_redirection_token(current->next->word))
            {
                print_syntax_error(redirection_type(current->next->word));
                return true;
            }
        }
        current = current->next;
    }
    return false;
}
