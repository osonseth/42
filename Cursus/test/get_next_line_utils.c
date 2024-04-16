/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:11 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/11 18:16:49 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int (i) = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen_of_line(char *str)
{
	int (i) = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

bool	check_eol(char *str)
{
	int (i) = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = '\0';
        i++;
    }
}

