/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:34:19 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/12 13:43:11 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	putstr(char *str, int *j, int * total)
{
	int	i;

	i = *j;
	while (i > 0)
	{
		*total+= write(1, &str[i -1], 1);
		i--;
	}
}
void putnbr(int n,int *total)
{
	char(tab)[11];
	int(i) = 0;
	long int(nb) = n;
	if (nb == 0)
	{
		*total+= write(1, " 0", 2);
		return ;
	}

	if (nb < 0)
		*total+= write(1, "-", 1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	tab[i] = '\0';
	putstr(tab, &i,total);
}

int	main(void)
{
	int i = -123456;
	int total = 0;
	putnbr(i,&total);
	printf("\n----------------------\n");
	printf("%d\n",total);
}