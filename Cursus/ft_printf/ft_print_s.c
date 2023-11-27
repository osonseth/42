/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:36:08 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/25 23:00:31 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	ft_print_s(char *str, lst *sc)
{
	while (*str)
	{
        sc->total_len += write(1,str,1);
		str++;
	}
}