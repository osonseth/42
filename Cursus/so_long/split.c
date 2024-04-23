/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 02:10:15 by max               #+#    #+#             */
/*   Updated: 2024/04/23 18:23:34 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_words(char *str, char c)
{
	bool	new_word;
	int		count_words;

	new_word = false;
	count_words = 0;
	if (str)
	{
		while (*str)
		{
			if (*str != c && new_word == false)
			{
				new_word = true;
				count_words++;
			}
			else if (*str == c)
			{
				new_word = false;
			}
			str++;
		}
	}
	return (count_words);
}

int	ft_strlen_split(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_strcpy_split(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_split(char const *s, t_data *data, char c)
{
	char	**tab;
	int		i;

	i = 0;
	data->split_new_words = false;
	data->map_height = ft_count_words((char *)s, c);
	tab = ft_calloc(data->map_height, sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c && data->split_new_words == false)
		{
			data->split_new_words = true;
			tab[i] = malloc(1 + ft_strlen_split(s, c) * sizeof(char));
			if (tab[i] == NULL)
				clear_array_split(tab, i);
			ft_strcpy_split(tab[i], s, ft_strlen_split(s, c));
			i++;
		}
		else if (*s == c && data->split_new_words == true)
			data->split_new_words = false;
		s++;
	}
	return (tab);
}

void	check_newline(char *map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i] == '\n' && map[i - 1] == '\n')
		{
			free(map);
			display_error("Error\nInvalid map");
		}
		i++;
	}
}
