/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:18:47 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 12:58:52 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len < len_little)
		return (NULL);
	while (len > 0)
	{
		if (!ft_strncmp(big, little, len_little))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

/* #include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char big[] = "hfwhrewlqkrhjqwlkreyo";
	char little[] = "yo";
	printf("%s\n", ft_strnstr(big, little, 40));
	printf("%s\n", strnstr(big, little, 40));
} */
