/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:18:47 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/12 20:10:21 by mmauchre         ###   ########.fr       */
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
		if (!ft_strncmp(big, little, len_little) && len >= len_little)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char big[] = "lorem ipsum dolor sit amet";
	char little[] = "dolor";
	printf("%s\n", ft_strnstr(big, little, 15));
} */
