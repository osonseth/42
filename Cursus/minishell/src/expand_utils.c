/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:43:15 by max               #+#    #+#             */
/*   Updated: 2024/07/10 11:45:47 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int skip_to_closing_brace(char *word)
{
    int i;
    i = 0;
    while (word[i] && word[i] != CLOSING_BRACE)
        i++;
    if (word[i] == CLOSING_BRACE)
        i++;
    return i + 2;
}

int skip_to_end_of_variable(char *word)
{
    int i;
    i = 0;
    while (is_alnum_or_underscore(word[i]))
        i++;
    return i + 1;
}
int ft_strlen_variable_name_with_brace(char *word)
{
    int i;
    i = 0;
    while (word[i] != CLOSING_BRACE)
        i++;
    return i;
}
int ft_strlen_variable_name_without_brace(char *word)
{
    int i;
    i = 0;
    while (is_alnum_or_underscore(word[i]))
        i++;
    return i;
}
void ft_strncpy_variable_name(char *dest, char *src, int len)
{
    int i;
    i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}