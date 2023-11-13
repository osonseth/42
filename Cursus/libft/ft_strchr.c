/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:09 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/12 23:05:39 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
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
	
	
	char s[] = "tripouille";
	
	 printf ("%s\n",ft_strchr(s, 't' + 256)); 
	write(1, "\n", 1);
	
	return (0);
} */
