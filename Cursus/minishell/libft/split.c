/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:40:24 by mmauchre          #+#    #+#             */
/*   Updated: 2024/06/24 18:48:43 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
}

static int	count_words(char *str)
{
	int		words;
	bool	new_words;

	new_words = false;
	words = 0;
	while (*str)
	{
		if (*str != 32 && *str != 9 && new_words == false)
		{
			words++;
			new_words = true;
		}
		if (*str == 32 || *str == 9)
			new_words = false;
		str++;
	}
	return (words);
}

static int	strlen_split(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 32 && str[i] != 9 && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*strcpy_split(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 9 && src[i] != 32 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split(char *str)
{
	char	**array;
	int		words;

	int (i) = 0;
	words = count_words(str);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (i < words)
	{
		while ((*str == 9 || *str == 32) && *str != '\0')
			str++;
		array[i] = malloc((1 + strlen_split(str)) * sizeof(char));
		if (array[i] == NULL)
		{
			clean_split(array, i);
			return (NULL);
		}
		strcpy_split(array[i], str);
		while (*str != 32 && *str != 9 && *str != '\0')
			str++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
