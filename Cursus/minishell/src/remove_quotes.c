/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:22:17 by max               #+#    #+#             */
/*   Updated: 2024/07/10 22:23:31 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int calculate_new_len(char *word, t_data *data)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (word[i])
	{
		opening_and_closing_quotes(word[i], data);
		if (word[i] != '"' && word[i] != '\'')
			len++;
		if (word[i] == '"' && data->simple_quote)
			len++;
		if (word[i] == '\'' && data->double_quote)
			len++;
		i++;
	}
	return len;
}
static void copy_char(char *nw, char *w, int *i, int *j)
{
	*nw = *w;
	(*i)++;
	(*j)++;
}
static char *ft_strcpy_new_word(char *word, char *new_word, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (word[i])
	{
		opening_and_closing_quotes(word[i], data);
		if (word[i] != '"' && word[i] != '\'')
			copy_char(&new_word[j], &word[i], &i, &j);
		else if (word[i] == '"' && data->simple_quote)
			copy_char(&new_word[j], &word[i], &i, &j);
		else if (word[i] == '\'' && data->double_quote)
			copy_char(&new_word[j], &word[i], &i, &j);
		else
			i++;
	}
	new_word[j] = '\0';
	return new_word;
}

char *remove_unnecessary_quotes(char *word, t_data *data)
{
	char *new_word;
	int len;
	len = calculate_new_len(word, data);
	new_word = malloc((len + 1) * sizeof(char));
	if (!new_word)
		memory_error(data);
	new_word = ft_strcpy_new_word(word, new_word, data);
	if (word)
		free(word);
	return new_word;
}