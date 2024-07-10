/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:20:01 by max               #+#    #+#             */
/*   Updated: 2024/07/09 12:49:40 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int end_of_the_variable_name(char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i] && str[i] != CLOSING_BRACE)
// 		i++;
// 	return i + 2;
// }

// int strlen_variable_name(char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i] && str[i] != '}')
// 		i++;

// 	return i;
// }

// int calculate_expanded_words(char *str)
// {

// 	int variable_name_lenght;
// 	variable_name_lenght = strlen_variable_name(str);
// 	char *variable_name = malloc((1 + variable_name_lenght) * sizeof(char));
// 	/*implémenter l'erreur avec la structure data
// 	if( !variable_name)
// 		memory_error
// 	*/
// 	variable_name[variable_name_lenght] = '\0';

// 	int i;
// 	i = 0;

// 	while (str[i] && str[i] != CLOSING_BRACE)
// 	{
// 		variable_name[i] = str[i];
// 		i++;
// 	}

// 	return (ft_strlen(getenv(variable_name)) - 3);
// }

// int calculate_expanded_lenght(char *token, t_data *data)
// {
// 	int i;
// 	int len;
// 	i = 0;
// 	len = 0;
// 	while (token[i])
// 	{
// 		opening_and_closing_quotes(token[i], data);
// 		if (!ft_strncmp(&token[i], "${", 2))
// 		{
// 			len += calculate_expanded_words(&token[i + 2]);
// 			i = end_of_the_variable_name(&token[i + 2]);
// 		}
// 		else
// 		{
// 			len++;
// 			i++;
// 		}
// 	}
// 	return len;
// }

int end_of_the_variable_name(char *str)
{
    int i;
    i = 0;
    while (str[i] && str[i] != CLOSING_BRACE)
        i++;
    return i;
}

int strlen_variable_name(char *str)
{
    int i;
    i = 0;
    while (str[i] && str[i] != '}')
        i++;

    return i;
}

int calculate_expanded_words(char *str)
{

    int variable_name_lenght;
    variable_name_lenght = strlen_variable_name(str);
    char *variable_name = malloc((1 + variable_name_lenght) * sizeof(char));
    /*implémenter l'erreur avec la structure data
    if( !variable_name)
        memory_error
    */
    variable_name[variable_name_lenght] = '\0';

    int i;
    i = 0;

    while (str[i] && str[i] != '}')
    {
        variable_name[i] = str[i];
        i++;
    }

    return (ft_strlen(getenv(variable_name)) - 3);
}
int calculate_expanded_lenght(t_data *data)
{
    int i;
    int lenght;
    i = 0;
    lenght = 0;
    while (data->line[i])
    {

        if (data->line[i] == '$' && data->line[i + 1] == '{')
        {
            lenght += calculate_expanded_words(&data->line[i + 2]);
            end_of_the_variable_name(&data->line[i], &i);
        }
        else
            lenght++;
        i++;
    }
    return lenght;
}