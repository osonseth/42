/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:26:03 by max               #+#    #+#             */
/*   Updated: 2024/07/16 12:00:15 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *remove_dollars_before_quote(char *str, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (str[i])
	{
		opening_and_closing_quotes(str[i], data);
		if ((!strncmp(&str[i], "$\"", 2) || !strncmp(&str[i], "$'", 2)) && !data->simple_quote & !data->double_quote)
			i++;
		else if (!strncmp(&str[i], "$", 1) && ft_isdigit(str[i + 1]) && !data->simple_quote)
			i += 2;
		else
			str[j++] = str[i++];
	}
	while (str[j])
	{
		str[j] = '\0';
		j++;
	}
	return str;
}

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
/*
Crée le nouveau token avec les varibles expand (via list des valeur récupérer avant) et le renvoie a la fonction principale
*/

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
			expanded_word[j++] = word[i++];
	}
	quotes_reset(data);
	return expanded_word;
}

/*
 no expand  : renvoie le token tel quel
 calcule de la len du nouveau token avec les expands
 crée le token avec les expands
*/
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
}
/*
Récursivité sur les tokens afin d'expand la valeur des variables d'env
expand management  		  : fonction pricipale
remove unnecessary quotes : enleve les quotes hors quote du token

*/
void recursive_handle_expand_token(t_tokens *token, t_data *data)
{
	if (token == NULL)
		return;
	token->word = expand_management(token->word, data);
	token->word = remove_unnecessary_quotes(token->word, data);
	clean_variable_lst(data->variable);
	data->variable = NULL;
	recursive_handle_expand_token(token->next, data);
}
