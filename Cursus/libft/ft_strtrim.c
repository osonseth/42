/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:20:28 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/14 17:16:02 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check_char_trim(const char c1, const char *c2)
{
	while (*c2)
	{
		if (c1 == *c2)
			return (1);
		c2++;
	}
	return (0);
}

static int	ft_count_trim(char const *s1, char const *set, char **p)
{
	int	len;
	int	trim;

	trim = 0;
	len = ft_strlen(s1);
	while (ft_check_char_trim(s1[len - 1], set))
	{
		trim++;
		len--;
	}
	while (ft_check_char_trim(*s1, set))
	{
		trim++;
		s1++;
	}
	*p = (char *)s1;
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		total_len;
	int		final_size;
	char	*p;
	char	*str;

	p = NULL;
	total_len = ft_strlen(s1);
	final_size = total_len - ft_count_trim(s1, set, &p);
	if (final_size < 0)
		final_size = 0;
	str = malloc((final_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, p, final_size + 1);
	return (str);
}

/* int	main(void)
{
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char set[] = " ";

	printf("%s\n", ft_strtrim(s1, set));
} */