/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:27:31 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 12:16:47 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int s1[] = {1, 3, 6, 21647, 9, 5, 5};
	int s2[] = {1, 3, 6, 5, 9, 5, 4};

	char str[]="max";
	char str1[]="mbx";

	printf("%d\n", ft_memcmp(s1, s2,28));
	printf("%d\n", memcmp(s1, s2, 28));
} */