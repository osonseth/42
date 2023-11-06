/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:03:22 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 15:36:45 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int	i;

	i = 0;
	char str[] = "coucou";
	char str2[] = "coucou";
	int tab[] = {1, 255, 3, 4, 5};
	int tab2[] = {1, 255, 3, 4, 5};
	ft_bzero(str, 3);
	bzero(str2, 3);
	ft_bzero(tab, 4);
	bzero(tab2, 4);
	printf("%s \n%s \n", str, str2);
	while (i < 5)
	{
		printf("%d %d\n", tab[i], tab2[i]);
		i++;
	}
} */
