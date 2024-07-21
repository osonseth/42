/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:22:17 by max               #+#    #+#             */
/*   Updated: 2024/07/21 09:05:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void remove_quotes_in_place(char *str, t_data *data)
{
    int i = 0;
    int j = 0;

    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);
        
        if (str[i] != '"' && str[i] != '\'')
            str[j++] = str[i];
        else if (str[i] == '"' && data->simple_quote)
            str[j++] = str[i];
        else if (str[i] == '\'' && data->double_quote)
            str[j++] = str[i];
        
        i++;
    }
    while (str[j])
        str[j++] = '\0';
}


char *remove_unnecessary_quotes(char *word, t_data *data)
{
	if (!word)
		return NULL;
	remove_quotes_in_place(word, data);
	return word;
}
