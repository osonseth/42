/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:17:25 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/11 19:12:49 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int	ft_count_digit(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;

	digit = ft_count_digit(n);
	str = malloc((digit + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
	}
	str[digit] = '\0';
	while (n != 0)
	{
		str[digit - 1] = ft_abs(n % 10) + '0';
		digit--;
		n /= 10;
	}
	return (str);
}

/* int	main(void)
{
	int	n;

	n = INT_MIN;
	printf("%s\n", ft_itoa(n));
} */
