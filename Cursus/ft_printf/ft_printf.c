/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/04 19:04:43 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_treat_flag(va_list arg, const char *format, int *total_return)
{ 
	while ( )
}

int	ft_printf(const char *format, ...)
{
	int (total_return) = 0;
	int (i) = 0;
	int (j) = 0;
	va_list(arg);
	va_start(arg, format);
	while (format[i + j])
	{
		
		if (format[i + j] == '%')
			ft_treat_flag(arg, &format[i + j], &total_return);
		i++;
	}
	va_end(arg);
	return (total_return);
}

#include <limits.h>

int	main(void)
{
	int test = 0;
	void *p = &test;
	unsigned long int n = (unsigned long int)p;
	printf("%p\n", p);
	ft_flag_p(n, &data);
	printf("\n");
}