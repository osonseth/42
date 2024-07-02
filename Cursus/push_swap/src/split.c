/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:30:32 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/16 12:06:34 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	clean_split(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
	array = NULL;
	display_error();
}

static int	count_words(char *str, char c)
{
	int		words;
	bool	new_words;

	new_words = false;
	words = 0;
	while (*str)
	{
		if (*str != c && new_words == false)
		{
			words++;
			new_words = true;
		}
		if (*str == c && new_words == true)
			new_words = false;
		str++;
	}
	return (words);
}

static int	strlen_split(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*strcpy_split(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split(t_data *data, char *str, char c)
{
	char	**array;
	int		i;

	i = 0;
	data->array_number_height = count_words(str, c);
	array = malloc(data->array_number_height * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (i < data->array_number_height)
	{
		while (*str == c && *str != '\0')
			str++;
		array[i] = malloc((1 + strlen_split(str, c)) * sizeof(char));
		if (array[i] == NULL)
		{
			free(str);
			clean_split(array, i);
		}
		strcpy_split(array[i], str, c);
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	return (array);
}
