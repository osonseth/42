/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:55 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:00 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src)
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

/* #include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[20];
	size_t	size;
	size_t	result_original;
	char	dest2[20];
	size_t	result_custom;

	char src[] = "Hello, world!";
	size = 33;
	// Appel de la fonction d'origine strlcpy
	result_original = strlcpy(dest, src, size);
	// printf("Original strlcpy result: %d\n", result_original);
	// Appel de votre fonction ft_strlcpy
	result_custom = ft_strlcpy(dest2, src, size);
	// printf("Custom ft_strlcpy result: %d\n", result_custom);
	printf("Original strlcpy result: %zu\n", result_original);
	printf("Custom ft_strlcpy result: %zu\n", result_custom);
	// Comparaison des résultats
	if (result_original == result_custom)
	{
		printf("Results match.\n");
	}
	else
	{
		printf("Results do not match.\n");
	}
	printf("%s\n", dest);
	printf("%s\n", dest2);
	return (0);
}
 */