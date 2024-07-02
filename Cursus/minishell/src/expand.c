/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:20:01 by max               #+#    #+#             */
/*   Updated: 2024/06/27 22:10:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void end_of_the_variable_name(char *str, int *i)
{
    while (*str && *str != '}')
    {
        (*i)++;
        str++;
    }
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

    return (ft_strlen(getenv(variable_name)));
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