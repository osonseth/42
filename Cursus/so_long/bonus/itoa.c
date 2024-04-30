/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:43:19 by max               #+#    #+#             */
/*   Updated: 2024/04/30 11:29:23 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_abs_solong(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_count_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(t_data *data, int n)
{
	int		digit;
	char	*str;

	digit = ft_count_digit(n);
	str = malloc((digit + 1) * sizeof(char));
	if (!str)
		clean_all(data, "Error\nMemory allocation error");
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
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
