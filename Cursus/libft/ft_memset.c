/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:07 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/13 12:47:39 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	i;

	i = 0;
	char str[] = "";
	char str2[] = "";
	int tab[] = {1, 255, 3, 4, 5};
	int tab2[] = {1, 255, 3, 4, 5};
	ft_memset(str, '\0', 1);
	memset(str2, '\0', 1);
	ft_memset(tab, 0, 20);
	memset(tab2, 0, 20);
	printf("%s \n%s \n", str, str2);
	while (i < 5)
	{
		printf("%d %d\n", tab[i], tab2[i]);
		i++;
	}
} */
