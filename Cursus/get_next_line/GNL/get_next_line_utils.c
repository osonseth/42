/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:11 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/10 03:29:50 by mmauchre         ###   ########.fr       */
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
	int(i) = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

bool	check_eol(char *str)
{
	int(i) = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

bool	check_eof(char *str)
{
	int(i) = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (true);
		i++;
	}
	return (false);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *s)
{
	char	*dest;

	dest = malloc(1 + ft_strlen(s) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
