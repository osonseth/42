/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:55 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/12 17:44:41 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <sys/types.h>


size_t	strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*osrc;
	size_t		nleft;

	osrc = src;
	nleft = dsize;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			if ((*dst++ = *src++) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[20];
	size_t	size;
	size_t	result_original;
	char	dest2[20];
	size_t	result_custom;

	char src[] = "lorem ipsum dolor sit amet";
	size = 0;

	result_original = strlcpy(dest, src, size);

	result_custom = ft_strlcpy(dest2, src, size);

	printf("Original strlcpy result: %zu\n", result_original);
	printf("Custom ft_strlcpy result: %zu\n", result_custom);

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
} */
