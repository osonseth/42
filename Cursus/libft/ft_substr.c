/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:29:40 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/15 18:16:07 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mini(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(mini(len, ft_strlen(s + start)) + 1);
	if (!str)
		return (NULL);
	j = mini(len, ft_strlen(s + start));
	while (i < j)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>

int	main(void)
{

	char * s = ft_substr("tripouille", 0, 42000);
	printf("%s\n",s);


} */