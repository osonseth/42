/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:12:53 by max               #+#    #+#             */
/*   Updated: 2024/07/10 08:17:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void ft_strcpy_token(char *dst, char *src, int len)
{
    int i;

    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
static char *ft_strdup_token(char *s, int len)
{
    char *dest;

    dest = malloc((1 + len) * sizeof(char));

    if (!dest)
        return (NULL);
    ft_strcpy_token(dest, s, len);
    return (dest);
}

static int ft_strlen_token(char *str, t_data *data)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);
        if (is_space(str[i]) && !data->double_quote && !data->simple_quote)
            break;
        i++;
    }
    quotes_reset(data);
    return (i);
}
int create_token(char *str, t_commands_table *table, t_data *data)
{
    int len;
    len = ft_strlen_token(str, data);
    char *token;
    token = ft_strdup_token(str, len);
    if (token == NULL)
        memory_error(data);

    token_node_add_back(&(table->token), new_token_node(token), data);

    return len - 1;
}

void node_tokenization(t_data *data, t_commands_table *table)
{
    int i;
    i = 0;

    while (table->simple_cmd[i])
    {
        if (!is_space(table->simple_cmd[i]))
            i += create_token(&table->simple_cmd[i], table, data);
        i++;
    }
}
