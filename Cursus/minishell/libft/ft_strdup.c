/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:47:35 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/03 11:19:34 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy_simple_cmd(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '|')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup_simple_cmd(char *s)
{
	char	*dest;

	dest = malloc(1 + ft_strlen_simple_cmd(s) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy_simple_cmd(dest, s);
	return (dest);
}

static void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

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
