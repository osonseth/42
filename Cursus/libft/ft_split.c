/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:03:32 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/14 17:17:58 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static int	ft_strlen_split(char const *s, char c)
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

static void	ft_strcpy_split(char *dst, const char *src, int size)
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	bool	new_words;

	i = 0;
	new_words = false;
	words = ft_count_words((char *)s, c);
	tab = ft_calloc(1 + words, sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c && new_words == false)
		{
			new_words = true;
			tab[i] = malloc(1 + ft_strlen_split(s, c) * sizeof(char));
			ft_strcpy_split(tab[i], s, ft_strlen_split(s, c));
			i++;
		}
		else if (*s == c && new_words == true)
			new_words = false;
		s++;
	}
	return (tab);
}

/* int	main(void)

{
	char c;
	char **tab;

	char *str = strdup("ok tonton on est la");
	c = ' ';
	tab = ft_split(str, c);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", tab[i]);
	}

	return (0);
}
 */