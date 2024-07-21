/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:13:21 by max               #+#    #+#             */
/*   Updated: 2024/07/19 00:44:08 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *input_redirect_token(void)
{
    char *tmp;

    tmp = ft_strdup("<");
    if (tmp == NULL)
        return NULL;
    return tmp;
}

char *output_redirect_token(void)
{  
    char *tmp;

    tmp = ft_strdup(">");
    if (tmp == NULL)
        return NULL;
    return tmp;
}

char *append_redirect_token(void)
{ 
    char *tmp;

    tmp = ft_strdup(">>");
    if (tmp == NULL)
        return NULL;
    return tmp;
}

char *heredoc_token(void)
{
    char *tmp;

    tmp = ft_strdup("<<");
    if (tmp == NULL)
        return NULL;
    return tmp;
}

char *redirection_token_content(char *str)
{
    char *tmp;

    tmp = ft_strdup_redir_token_content(str);
    if (tmp == NULL)
        return NULL;
    return tmp;
}