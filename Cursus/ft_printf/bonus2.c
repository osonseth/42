/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:15:50 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/12 19:52:47 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str, int *j)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	(*j) += (i - 1);
	return (result);
}
