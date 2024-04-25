/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:55 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/25 04:24:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// fonction qui affiche un char

void	ft_flag_c(char c, int *total_return)
{
	*total_return += write(1, &c, 1);
}

// fonction qui affiche une string

void	ft_flag_s(char *str, int *total_return)
{
	if (!str)
	{
		*total_return += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*total_return += write(1, str, 1);
		str++;
	}
}
// fonction qui retoune la valeur absolue d'un int

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
// fonction qui affiche la valeur d'un int

void	ft_flag_d(int n, int *total_return)
{
	char	c;

	if (n == -2147483648)
	{
		*total_return += write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		*total_return += write(1, "-", 1);
		n = ft_abs(n);
	}
	if (n > 9)
	{
		ft_flag_d(n / 10, total_return);
		ft_flag_d(n % 10, total_return);
	}
	else
	{
		c = n + '0';
		*total_return += write(1, &c, 1);
	}
}
// fonction qui affiche la valeur d'un unsigned int

void	ft_flag_u(unsigned int n, int *total_return)
{
	char	c;

	if (n > 9)
	{
		ft_flag_u(n / 10, total_return);
		ft_flag_u(n % 10, total_return);
	}
	else
	{
		c = n + '0';
		*total_return += write(1, &c, 1);
	}
}
