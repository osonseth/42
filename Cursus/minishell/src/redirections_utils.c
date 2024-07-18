/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:17:52 by max               #+#    #+#             */
/*   Updated: 2024/07/18 09:18:15 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_strcpy_redir_token_content(char *dst, const char *src)
{
    size_t i;

    i = 0;
    while (src[i] && src[i] != '<' && src[i] != '>')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int ft_strlen_redir_token_content(char *str)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i] && str[i] != '<' && str[i] != '>')
        i++;
    return (i);
}

char *ft_strdup_redir_token_content(char *s)
{
    char *dest;

    dest = malloc(1 + ft_strlen_redir_token_content(s) * sizeof(char));
    if (!dest)
        return (NULL);
    ft_strcpy_redir_token_content(dest, s);

    return (dest);
}