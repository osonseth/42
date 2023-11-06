/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:08:00 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 18:49:49 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= destlen)
	{
		return (size + srclen);
	}
	if (size > destlen)
	{
		while (src[i] && i + destlen < size - 1)
		{
			dst[destlen + i] = src[i];
			i++;
		}
		dst[destlen + i] = '\0';
	}
	return (destlen + srclen);
}

/* #include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1a[10] = "Test1";
	char s2a[] = "OK";
	char s1b[10] = "Test1";
	char s2b[] = "OK";
	char s3a[10] = "Same";
	char s4a[] = "Size";
	char s3b[10] = "Same";
	char s4b[] = "Size";
	char s5a[20] = "Shorter";
	char s6a[] = "ThanMyself";
	char s5b[20] = "Shorter";
	char s6b[] = "ThanMyself";
	char s7a[20] = "Shorter";
	char s8a[] = "ThanMyself";
	char s7b[20] = "Shorter";
	char s8b[] = "ThanMyself";
	printf("%s\n", ft_strlcat(s1a, s2a, 6) == strlcat(s1b, s2b,
			6) ? "Success" : "Fail");
	printf("%s\n", strcmp(s1a, s1b) == 0 && strcmp(s2a,
			s2b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s3a, s4a, 10) == strlcat(s3b, s4b,
			10) ? "Success" : "Fail");
	printf("%s\n", strcmp(s3a, s3b) == 0 && strcmp(s4a,
			s4b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s5a, s6a, 4) == strlcat(s5b, s6b,
			4) ? "Success" : "Fail");
	printf("%s\n", strcmp(s5a, s5b) == 0 && strcmp(s6a,
			s6b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s7a, s8a, 0) == strlcat(s7b, s8b,
			0) ? "Success" : "Fail");
	printf("%s\n", strcmp(s7a, s7b) == 0 && strcmp(s8a,
			s8b) == 0 ? "Success" : "Fail");
	printf("\n\nDetails:\n");
	printf("%s:%s\n%s:%s\n", s1a, s1b, s2a, s2b);
	printf("%s:%s\n%s:%s\n", s3a, s3b, s4a, s4b);
	printf("%s:%s\n%s:%s\n", s5a, s5b, s6a, s6b);
	printf("%s:%s\n%s:%s\n", s7a, s7b, s8a, s8b);
} */
