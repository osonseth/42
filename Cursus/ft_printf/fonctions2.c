/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:50:11 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/29 00:49:13 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

// fonction qui affiche un nombre au format majuscule héxadécimal
void	ft_flag_X(unsigned int n, t_struct *data)
{
	if (n > 16)
	{
		ft_flag_X(n / 16, data);
		ft_flag_X(n % 16, data);
	}
	else
	{
		data->total_len += write(1, "0123456789ABCDEF" + (n), 1);
	}
}
// fonction qui affiche un nombre au format minuscule héxadécimal

void	ft_flag_x(unsigned int n, t_struct *data)
{
	if (n > 16)
	{
		ft_flag_x(n / 16, data);
		ft_flag_x(n % 16, data);
	}
	else
	{
		data->total_len += write(1, "0123456789abcdef" + (n), 1);
	}
}
// fonction qui affiche l'adresse d'un pointeur en héxadécimal

void	ft_flag_p(unsigned long int n, t_struct *data)
{
	static bool(prefix) = false;
	if (prefix == false)
	{
		data->total_len += write(1, "0x", 2);
		prefix = true;
	}
	if (n > 16)
	{
		ft_flag_p(n / 16, data);
		ft_flag_p(n % 16, data);
	}
	else
	{
		data->total_len += write(1, "0123456789abcdef" + (n), 1);
	}
}
