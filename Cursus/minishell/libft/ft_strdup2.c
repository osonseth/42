/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:11:35 by mmauchre          #+#    #+#             */
/*   Updated: 2024/06/20 13:27:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_two(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '<' && str[i] != '>' && str[i] != '|'
		&& str[i] != 9 && str[i] != 32)
	{
		i++;
	}
	return (i);
}

static void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '<' && src[i] != '>' && src[i] != '|'
		&& src[i] != 9 && src[i] != 32)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup_two(char *s)
{
	char	*dest;

	dest = malloc(1 + ft_strlen_two(s) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
