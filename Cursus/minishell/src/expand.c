/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:26:03 by max               #+#    #+#             */
/*   Updated: 2024/07/10 18:28:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_strncpy_expanded_word(char *variable_value, char *expanded_word)
{
	int len;
	int i;
	if (!variable_value)
		return;

	len = ft_strlen(variable_value);

	i = 0;

	while (i < len)
	{
		

		expanded_word[i] = variable_value[i];

		i++;
	}
}

static char *make_expanded_word(char *word, char *expanded_word, t_data *data)
{

	int(i) = 0;
	int(j) = 0;
	t_variable(*current) = data->variable;

	while (word[i])
	{

		opening_and_closing_quotes(word[i], data);
		if (!ft_strncmp(&word[i], "${", 2) && is_alpha_or_underscore(word[i + 2]) && !data->simple_quote)
		{
			ft_strncpy_expanded_word(current->value, &expanded_word[j]);
			i += skip_to_closing_brace(&word[i + 2]);
			j += ft_strlen(current->value);
			current = current->next;
		}
		else if (word[i] == '$' && is_alpha_or_underscore(word[i + 1]) && !data->simple_quote)
		{
			ft_strncpy_expanded_word(current->value, &expanded_word[j]);
			i += skip_to_end_of_variable(&word[i + 1]);
			j += ft_strlen(current->value);
			current = current->next;
		}
		else
		{
			expanded_word[j] = word[i];
			i++;
			j++;
		}
	}
	quotes_reset(data);
    return expanded_word;
}

char *expand_management(char *word, t_data *data)
{
	if (no_expand(word, data))
		return word;
	int expanded_word_len;
	char *expanded_word;
	expanded_word_len = calculate_expanded_len(word, data);

	expanded_word = malloc((expanded_word_len + 1) * sizeof(char));
	if (!expanded_word)
		memory_error(data);
	expanded_word[expanded_word_len] = '\0';
	expanded_word = make_expanded_word(word, expanded_word, data);
	if (word)
		free(word);
	return expanded_word;
	// a changer pour expanded word
}
