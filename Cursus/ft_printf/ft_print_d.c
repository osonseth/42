/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:04:49 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/25 23:00:54 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_print_d(int n, lst *sc)
{
	char	c;

	if (n == -2147483648)
	{
		sc->total_len = write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		sc->total_len = write(1, "-", 1);
		n = ft_abs(n);
	}
	if (n > 9)
	{
		ft_print_d(n / 10, sc);
		ft_print_d(n % 10, sc);
	}
	else
	{
		c = n + '0';
		sc->total_len += write(1, &c, 1);
	}
}

