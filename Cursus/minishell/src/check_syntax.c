/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:55:48 by max               #+#    #+#             */
/*   Updated: 2024/07/03 23:40:23 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void update_cmd_table(t_commands_table *table, t_data *data)
{
    table->syntaxe_error = true;
    table->message_error = ft_strdup("Minishell: Bad substitution (Empty brace, brace not closed or bad syntaxe)\n");
    if (table->message_error == NULL)
        clean_all(data);
}

bool brace_not_closed_or_bad_syntax(char *str)
{
    while (*str)
    {
        if (!is_alnum_or_underscore(*str) && *str != 125)
            return true;
        if (*str == 125)
            return false;
        str++;
    }
    return true;
}

bool expand_syntax_error(t_commands_table *table, t_data *data)
{
    char *str;
    str = table->simple_cmd;
    while (*str)
    {
        opening_and_closing_quotes(*str, data);
        if (*str == '$' && !data->simple_quote)
        {
            if (!ft_strncmp(str, "${", 2))
            {
                if (!is_alpha_or_underscore(str[2]) || brace_not_closed_or_bad_syntax(str + 2))
                {
                    update_cmd_table(table, data);
                    return true;
                }
            }
            else if (!is_alnum_or_underscore(str[1]) && str[1] != 9 && str[1] != 32)
            {
                update_cmd_table(table, data);
                return true;
            }
        }
        str++;
    }
    return false;
}

bool next_node_is_empty(char *str)
{
    while (*str && *str != '|')
    {
        if (!(*str == 32 || *str == 9))
            return true;
        str++;
    }
    return false;
}

void check_pipe(t_data *data)
{
    char *str;
    str = skype_space_ptr(data->line);
    if (*str == '|')
        print_syntax_error(data, PIPE);
    while (*str)
    {
        if (*str == '|')
        {
            if (!(next_node_is_empty(&str[1])))
                print_syntax_error(data, PIPE);
        }
        str++;
    }
}