/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:38:54 by max               #+#    #+#             */
/*   Updated: 2024/07/03 01:02:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_close_quote(t_data *data)
{
    if (data->simple_quote || data->double_quote)
        print_syntax_error(data, QUOTE);
}

void opening_and_closing_quotes(char c, t_data *data)
{

    if (c == '"' && data->simple_quote == false)
    {
        if (data->double_quote == false)
            data->double_quote = true;
        else
            data->double_quote = false;
    }
    else if (c == '\'' && data->double_quote == false)
    {
        if (data->simple_quote == false)
            data->simple_quote = true;
        else
            data->simple_quote = false;
    }
}

void check_quote(t_data *data)
{
    char *str;
    str = data->line;
    while (*str)
    {
        if (*str == '"' || *str == '\'')
            opening_and_closing_quotes(*str, data);
        else if (*str == '|')
        {
            check_close_quote(data);
            data->simple_quote = false;
            data->double_quote = false;
        }
        str++;
    }
    check_close_quote(data);
}
