/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:08:46 by max               #+#    #+#             */
/*   Updated: 2024/07/16 02:52:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_strlen_simple_cmd(char *str, t_data *data)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);
        if (str[i] == '|' && !data->double_quote && !data->simple_quote)
            return i;
        i++;
    }
    quotes_reset(data);
    return (i);
}

static void ft_strcpy_simple_cmd(char *dst, char *src, t_data *data)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        opening_and_closing_quotes(src[i], data);
        if (src[i] == '|' && !data->double_quote && !data->simple_quote)
            break;
        dst[i] = src[i];
        i++;
    }
    quotes_reset(data);
    dst[i] = '\0';
}

char *ft_strdup_simple_cmd(char *s, t_data *data)
{
    char *dest;
    dest = malloc(1 + ft_strlen_simple_cmd(s, data) * sizeof(char));

    if (!dest)
        return (NULL);
    ft_strcpy_simple_cmd(dest, s, data);
    return (dest);
}
