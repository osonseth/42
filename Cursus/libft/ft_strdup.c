/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:55:45 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/15 18:09:46 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src)
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

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = malloc(1 + ft_strlen(s) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}

/* #include <stdio.h>

int main ()
{
	char str[]="coucou c'est max!";
	printf("%s\n", ft_strdup(str));
} */