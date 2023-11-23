/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:34:32 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/13 03:30:24 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int main ()
{
	char str[]="";
	char str1[]="12345";

	printf("%ld\n",ft_strlen(str));
	printf("%ld\n",ft_strlen(str1));
	
	
	
	
} */