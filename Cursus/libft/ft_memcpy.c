/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:40:40 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 16:14:55 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int i;

	i = 0;
	char src[] = "coucou";
	char src2[] = "coucou";
	char dest[] = "000000";
	char dest2[] = "000000";
	int tab[] = {1, 2, 3, 4, 5, -325};
	int tab2[] = {1, 2, 3, 4, 5, -325};
	int dest_tab[] = {0, 0, 0, 0, 0, 0};
	int dest_tab2[] = {0, 0, 0, 0, 0, 0};

	int n = 6;

	printf("%s\n%s\n", dest, dest2);

	for (int i = 0; i < 6; i++)
	{
		printf("%d", dest_tab[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", dest_tab2[i]);
	}

	printf("\n--------------------------------------------------\n");

	ft_memcpy(dest, src, n);
	memcpy(dest2, src2, n);
	ft_memcpy(dest_tab, tab, 22);
	memcpy(dest_tab2, tab2, 22);

	printf("%s\n%s\n", dest, dest2);

	for (int i = 0; i < 6; i++)
	{
		printf("%d", dest_tab[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", dest_tab2[i]);
	}
	printf("\n");
} */