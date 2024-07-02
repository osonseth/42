/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:27:25 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/10 14:38:13 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_count_words(char *str, char c)
{
	bool	new_word;
	int		count_words;

	new_word = false;
	count_words = 0;
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
	return (count_words);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "ok";
	char c = ' ';

	printf("%d\n",ft_count_words(str, c));
} */