/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:00 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 14:35:54 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
		if (!ft_isdigit(*nptr))
			return (0);
	}
	if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/* int	main(void)
{
	char str[] = "+13465";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
} */