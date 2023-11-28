/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:55 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/28 18:54:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// fonction qui gère le flag %s

void	ft_flag_s(char *str, t_struct *data)
{
	while (*str)
	{
		data->total_len += write(1, str, 1);
		str++;
	}
}
// fonction qui retoune l'abs d'un int

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
// fonction qui gère le flag %s

void	ft_flag_d(int n, t_struct *data)
{
	char	c;

	if (n == -2147483648)
	{
		data->total_len += write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		data->total_len += write(1, "-", 1);
		n = ft_abs(n);
	}
	if (n > 9)
	{
		ft_flag_d(n / 10, data);
		ft_flag_d(n % 10, data);
	}
	else
	{
		c = n + '0';
		data->total_len += write(1, &c, 1);
	}
}
