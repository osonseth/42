/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:55:45 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 15:18:50 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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