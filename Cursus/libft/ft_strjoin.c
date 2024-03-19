/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:48:53 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/19 15:01:28 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *line, char *gnl)
{
	int		total_len;
	char	*str;
	int		i;

	total_len = ft_strlen(li) + ft_strlen(s2);
	str = malloc(1 + total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>

int main ()
{
	char    s1[] = "";
		char    s2[] = "dolor sit amet";

	printf("%s\n", ft_strjoin(s1,s2));
} */