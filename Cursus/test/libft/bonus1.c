/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/23 17:57:40 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>
#include <unistd.h>

// fonction qui affiche un int avec le flag space

void	ft_flag_di_and_space(int n, int *total_return)
{
	char (tab)[11];
	int (i) = 0;
	long int (nb) = n;
	if (nb == 0)
	{
		*total_return += write(1, " 0", 2);
		return ;
	}
	if (nb >= 0)
		*total_return += write(1, " ", 1);
	if (nb < 0)
	{
		*total_return += write(1, "-", 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	tab[i] = '\0';
	ft_putstr(tab, &i, total_return);
}
//fonction qui affiche un int avec le flag plus

void	ft_flag_di_and_plus(int n, int *total_return)
{
	char (tab)[11];
	int (i) = 0;
	long int (nb) = n;
	if (nb == 0)
	{
		*total_return += write(1, "+0", 2);
		return ;
	}
	if (nb >= 0)
		*total_return += write(1, "+", 1);
	if (nb < 0)
	{
		*total_return += write(1, "-", 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	tab[i] = '\0';
	ft_putstr(tab, &i, total_return);
}

// fonction qui affiche la valeur au format hexa précédé de 0x
void	ft_flag_dieze_and_x(unsigned int n, int *total_return)
{
	if (!n)
		*total_return += write(1, "0", 1);
	else
	{
		*total_return += write(1, "0x", 2);
		ft_flag_x(n, total_return);
	}
}

// fonction qui affiche la valeur au format hexa précédé de 0X

void	ft_flag_dieze_and_bigx(unsigned int n, int *total_return)
{
	if (!n)
		*total_return += write(1, "0", 1);
	else
	{
		*total_return += write(1, "0X", 2);
		ft_flag_bigx(n, total_return);
	}
}
/*fonction qui affiche une string (specialment pour ft_flag_di_and_space 
et ft_flag_di_and_plus)*/

void	ft_putstr(char *str, int *j, int *total_return)
{
	int	i;

	i = *j;
	while (i > 0)
	{
		*total_return += write(1, &str[i - 1], 1);
		i--;
	}
}
