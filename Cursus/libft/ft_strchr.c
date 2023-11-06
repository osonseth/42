/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:09 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 19:37:51 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (!c)
		return (p);
	return (p = NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "coucoumax";
	printf("%s\n", ft_strchr(str, 0));
	printf("%s\n", strchr(str, 0));
} */
