/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:48:10 by max               #+#    #+#             */
/*   Updated: 2024/07/21 22:20:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Check si il y'a des expand a faire dans le token
*/

bool no_expand(char *word, t_data *data)
{
    int i;
    i = 0;
    while (word[i])
    {
        opening_and_closing_quotes(word[i], data);
        if (!ft_strncmp(&word[i], "${", 2) && !data->simple_quote && is_alpha_or_underscore(word[i + 2]))
        {
            quotes_reset(data);
            return false;
        }
        else if (word[i] == '$' && !data->simple_quote && is_alpha_or_underscore(word[i + 1]))
        {
            quotes_reset(data);
            return false;
        }
        i++;
    }
    quotes_reset(data);
    return true;
}
/*
crée la liste des valeur de variable a expand et renvoie la leur len
*/
int make_var_value_lst_and_calculate_len(char *var_name, t_data *data)
{
    int var_value_len;

    var_value_len = ft_strlen(ft_getenv(var_name,data));
    if (!variable_node_add_back(&(data->variable), new_variable_node(ft_getenv(var_name,data))))
    {
        data->error = true;
        return 0;
    }
    return var_value_len;
}
/*
Recupere la len de la valeur des variable $
*/
int calculate_variable_value_with_brace_len(char *word, t_data *data)
{
    char *variable_name;
    int variable_len;
    int variable_value_len;

    variable_len = ft_strlen_variable_name_with_brace(word);
    variable_name = malloc((variable_len + 1) * sizeof(char));
    if (variable_name == NULL)
    {
        data->error = true;
        return 0;
    }
    ft_strncpy_variable_name(variable_name, word, variable_len);
    variable_value_len = make_var_value_lst_and_calculate_len(variable_name, data);
    if (data->error)
    {
        free(variable_name);
        return 0;
    }
    free(variable_name);
    return variable_value_len;
}
/*
Recupere la len de la valeur des variable ${}
*/
int calculate_variable_value_without_brace_len(char *word, t_data *data)
{
    char *variable_name;
    int variable_len;
    int variable_value_len;
    variable_len = ft_strlen_variable_name_without_brace(word);
    variable_name = malloc((variable_len + 1) * sizeof(char));
    if (variable_name == NULL)
    {
        data->error = true;
        return 0;
    }
    ft_strncpy_variable_name(variable_name, word, variable_len);
    variable_value_len = make_var_value_lst_and_calculate_len(variable_name, data);
    if (data->error)
    {
        free(variable_name);
        return 0;
    }
    free(variable_name);
    return variable_value_len;
}

/*
Quand trouve un ${} ou $ hors quote récupere et ajoute a la len total la len de la valeur de la variable via 2 sous fonction
*/
int calculate_expanded_len(char *word, t_data *data)
{
    int(i) = 0;
    int(expanded_len) = 0;
    while (word[i])
    {
        opening_and_closing_quotes(word[i], data);
        if (!ft_strncmp(&word[i], "${", 2) && is_alpha_or_underscore(word[i + 2]) && !data->simple_quote)
        {
            expanded_len += calculate_variable_value_with_brace_len(&word[i + 2], data);
            if (data->error)
                return 0;
            i += skip_to_closing_brace(&word[i + 2]);
        }
        else if (word[i] == '$' && is_alpha_or_underscore(word[i + 1]) && !data->simple_quote)
        {
            expanded_len += calculate_variable_value_without_brace_len(&word[i + 1], data);
            if (data->error)
                return 0;
            i += skip_to_end_of_variable(&word[i + 1]);
        }
        else
            increment(&i, &expanded_len);
    }
    return (quotes_reset(data), expanded_len);
}
