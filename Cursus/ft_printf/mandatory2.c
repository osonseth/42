/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:50:11 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/13 21:17:21 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdbool.h>

// fonction qui affiche un nombre au format majuscule héxadécimal

void	ft_flag_bigx(unsigned long int n, int *total_return)
{
	char (base)[] = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_flag_bigx(n / 16, total_return);
		ft_flag_bigx(n % 16, total_return);
	}
	else
	{
		*total_return += write(1, &base[n], 1);
	}
}
// fonction qui affiche un nombre au format minuscule héxadécimal

void	ft_flag_x(unsigned long int n, int *total_return)
{
	char (base)[] = "0123456789abcdef";
	if (n >= 16)
	{
		ft_flag_x(n / 16, total_return);
		ft_flag_x(n % 16, total_return);
	}
	else
	{
		*total_return += write(1, &base[n], 1);
	}
}
// fonction qui affiche l'adresse d'un pointeur en héxadécimal

void	ft_flag_p(unsigned long int n, int *total_return)
{
	if (!n)
		*total_return += write(1, "(nil)", 5);
	else
	{
		*total_return += write(1, "0x", 2);
		ft_flag_x(n, total_return);
	}
}
// fonction qui check que les chars de format soit des chars des bonus

int	check_bonus(char c)
{
	if (c == '+' || c == ' ' || c == '#' || c == '0' || c == '.' || c == '-'
		|| c == '%')
		return (true);
	return (false);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
