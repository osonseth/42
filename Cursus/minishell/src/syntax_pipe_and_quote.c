/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_and_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:55:48 by max               #+#    #+#             */
/*   Updated: 2024/07/16 11:36:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Initialise le bool et le message d'erreur si probleme de syntaxe trouvé
*/

static void update_cmd_table(t_commands_table *table, t_data *data)
{
    table->syntaxe_error = true;
    table->message_error = ft_strdup("Minishell: Bad substitution (Empty brace, brace not closed or bad syntaxe)\n");
    if (table->message_error == NULL)
        clean_all(data);
}

/*
Check la fermeture de ${ et la syntaxe a l'interieur des {}
*/
static bool brace_not_closed_or_bad_syntax(char *str)
{
    while (*str)
    {
        if (!is_alnum_or_underscore(*str) && *str != CLOSING_BRACE)
            return true;
        if (*str == CLOSING_BRACE)
            return false;
        str++;
    }
    return true;
}
/*
Check si il y'a rien entre 2 pipes
*/
static bool next_node_is_empty(char *str)
{
    while (*str && *str != '|')
    {
        if (!(*str == 32 || *str == 9))
            return true;
        str++;
    }
   return false;
}
/*

Check les erreurs de syntaxe pour ${}

*/
bool expand_has_syntax_errors(t_commands_table *table, t_data *data)
{
    char *str;
    str = table->simple_cmd;
    while (*str)
    {
        opening_and_closing_quotes(*str, data);
        if ((!ft_strncmp(str, "${", 2)) && !data->simple_quote)
        {

            if (!is_alpha_or_underscore(str[2]) || brace_not_closed_or_bad_syntax(str + 2))
            {
                update_cmd_table(table, data);
                quotes_reset(data);
                return true;
            }
        }
        str++;
    }
    quotes_reset(data);
    return false;
}

/*

Check les erreurs de syntaxe des pipes

*/
bool pipe_syntax_errors(t_data *data)
{
    char *str;
    str = skype_space_ptr(data->line);
    if (*str == '|')
    {
        print_syntax_error(PIPE);
        return true;
    }
    while (*str)
    {
        opening_and_closing_quotes(*str, data);
        if (*str == '|' && !data->double_quote && !data->simple_quote)
        {
            if (!(next_node_is_empty(&str[1])))
            {
                print_syntax_error(PIPE);
                return true;
            }
        }
        str++;
    }
    quotes_reset(data);
    return false;
}
