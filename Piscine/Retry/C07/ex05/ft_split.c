/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:05:19 by mmauchre          #+#    #+#             */
/*   Updated: 2023/09/27 16:12:36 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	check_word(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (false);
		str++;
	}
	return (true);
}

int	count_words(char *str, char *charset)
{
	int		i;
	int		count;
	bool	new_word;

	new_word = false;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (check_word(str[i], charset))
		{
			new_word = true;
		}
		if (!check_word(str[i], charset) && new_word == true)
		{
			count++;
			new_word = false;
		}
		if (str[i + 1] == '\0' && new_word == true)
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_make_all(char **tab, char *str, char *charset, int words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < words)
	{
		k = 0;
		while (!check_word(str[j], charset))
			j++;
		while (check_word(str[j], charset))
		{
			j++;
			k++;
		}
		j -= k;
		tab[i] = ft_strdup(&str[j], k);
		j += k;
		i++;
	}
	tab[i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;

	words = count_words(str, charset);
	tab = (char **)malloc((1 + words) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_make_all(tab, str, charset, words);
	return (tab);
}

/* int	main(void)
{
	char	**tab;

	char s1[] = "!";
	char s2[] = "";
	tab = ft_split(s2, s1);
	for (int i = 0; i < 1; i++)
	{
		printf("%s", tab[i]);
		printf("\n");
	}
	return (0);
} */
