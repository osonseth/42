/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:50:11 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/11 16:48:37 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

// fonction qui affiche un nombre au format majuscule héxadécimal

void	ft_flag_X(unsigned long int n, int *total_return)
{
	char (base)[] = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_flag_X(n / 16, total_return);
		ft_flag_X(n % 16, total_return);
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
