/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:48:10 by max               #+#    #+#             */
/*   Updated: 2024/07/10 15:25:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int make_var_value_lst_and_calculate_len(char *var_name, t_data *data)
{
    int var_value_len;

    var_value_len = ft_strlen(getenv(var_name));
    variable_node_add_back(&(data->variable), new_variable_node(getenv(var_name)), data);
    return var_value_len;
}
int calculate_variable_value_without_brace_len(char *word, t_data *data)
{
    char *variable_name;
    int variable_len;
    int variable_value_len;

    variable_len = ft_strlen_variable_name_with_brace(word);
    variable_name = malloc((variable_len + 1) * sizeof(char));
    if (variable_name == NULL)
        memory_error(data);
    ft_strncpy_variable_name(variable_name, word, variable_len);
    variable_value_len = make_var_value_lst_and_calculate_len(variable_name, data);
    free(variable_name);
    return variable_value_len;
}
int calculate_variable_value_brace_len(char *word, t_data *data)
{
    char *variable_name;
    int variable_len;
    int variable_value_len;

    variable_len = ft_strlen_variable_name_without_brace(word);
    variable_name = malloc((variable_len + 1) * sizeof(char));
    if (variable_name == NULL)
        memory_error(data);
    ft_strncpy_variable_name(variable_name, word, variable_len);
    variable_value_len = make_var_value_lst_and_calculate_len(variable_name, data);
    free(variable_name);
    return variable_value_len;
}

int calculate_expanded_len(char *word, t_data *data)
{
    int i;
    int expanded_len;

    expanded_len = 0;
    i = 0;
    while (word[i])
    {
        opening_and_closing_quotes(word[i], data);
        if (!ft_strncmp(&word[i], "${", 2) && is_alpha_or_underscore(word[i + 2]) && !data->simple_quote)
        {
            expanded_len += calculate_variable_value_without_brace_len(&word[i + 2], data);
            i += skip_to_closing_brace(&word[i + 2]);
        }
        else if (word[i] == '$' && is_alpha_or_underscore(word[i + 1]) && !data->simple_quote)
        {
            expanded_len += calculate_variable_value_brace_len(&word[i + 1], data);
            i += skip_to_end_of_variable(&word[i + 1]);
        }
        else
        {
            expanded_len++;
            i++;
        }
    }
    quotes_reset(data);
    return expanded_len;
}

