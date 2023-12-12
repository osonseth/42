/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/12 15:17:56 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

int	check_bonus(char c)
{
	if (c == '+' || c == ' ' || c == '#' || c == '0' || c == '.' || c == '-'
		|| c == '%')
		return (true);
	return (false);
}

static void	ft_putstr(char *str, int *j, int *total_return)
{
	int	i;

	i = *j;
	while (i > 0)
	{
		*total_return += write(1, &str[i - 1], 1);
		i--;
	}
}

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
