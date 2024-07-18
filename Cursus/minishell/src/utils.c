/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:38:42 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/18 08:32:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char *skype_space_ptr(char *str)
{
    while ((*str == 9 || *str == 32) && *str)
        str++;
    return str;
}
void skype_space(char *str, int *i)
{
    while (is_space(*str) && *str)
    {
        (*i)++;
        str++;
    }
}
void free_old_node(t_tokens *node)
{
    free(node->word);
    node->word = NULL;
    free(node);
}

/*
Check si un token contient au moins 1 redirection
*/
bool have_redirections(char *str, t_data *data)
{

    int i;
    i = 0;

    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);

        if ((str[i] == '<' || str[i] == '>') && !data->double_quote && !data->simple_quote)
            return true;
        i++;
    }
    quotes_reset(data);
    return false;
}
