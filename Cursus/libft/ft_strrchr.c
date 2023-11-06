/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:07:41 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 19:43:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (p);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "coucoumax";
	printf("%s\n", ft_strrchr(str, 0));
	printf("%s\n", strrchr(str, 0));
} */