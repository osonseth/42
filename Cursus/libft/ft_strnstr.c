/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:18:47 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/13 00:56:52 by mmauchre         ###   ########.fr       */
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
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (len > 0)
	{
		if (!ft_strncmp(big, little, len_little) && len >= len_little)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

// check(ft_strnstr(empty, "coucou", -1) == 0); showLeaks();

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char big[] = "";
	char little[] = "coucou";
	printf("%s\n", ft_strnstr(big, little, -1));
} */
