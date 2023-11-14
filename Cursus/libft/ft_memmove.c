/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:23:10 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/14 17:16:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "qwerty";
	char str2[] = "qwerty";
	int tab[] = {1, 2, -355465, 4, 5};
	int tab2[] = {1, 2, -355465, 4, 5};

	ft_memmove(str, &str[1], 3);
	memmove(str2, &str2[1], 3);
	ft_memmove(tab, &tab[1], 3);
	memmove(tab2, &tab2[1], 3);

	printf("%s\n", str);
	printf("%s\n", str2);

	for (int i = 0; i < 5; i++)
	{
		printf("%d", tab[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d", tab2[i]);
	}
	printf("\n");
} */

/* int	main(void)
{
	char src[] = "lorem ipsum dolor sit amet";
	char *dest;
	dest = src + 1;

	ft_memmove(dest, "consectetur", 5);
	write(1, dest, 22);
	write(1, "\n", 1);
} */