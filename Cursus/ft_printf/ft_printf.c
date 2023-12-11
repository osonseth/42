/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/11 16:49:10 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_treat_flag(va_list arg, const char *format, int *total_return)
{
	if (*format == 'd' || *format == 'i')
	{
		ft_flag_d(va_arg(arg, int), total_return);
	}
	else if (*format == 's')
	{
		ft_flag_s(va_arg(arg, char *), total_return);
	}
	else if (*format == 'c')
	{
		ft_flag_c((char)va_arg(arg, int), total_return);
	}
	else if (*format == 'u')
	{
		ft_flag_u(va_arg(arg, unsigned int), total_return);
	}
	else if (*format == 'p')
	{
		ft_flag_p(va_arg(arg, unsigned long int), total_return);
	}
	else if (*format == 'x')
	{
		ft_flag_x(va_arg(arg, unsigned long int), total_return);
	}
	else if (*format == 'X')
	{
		ft_flag_X(va_arg(arg, unsigned long int), total_return);
	}
}

int	ft_printf(const char *format, ...)
{
	int (total_return) = 0;
	int (i) = 0;
	va_list(arg);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			total_return += write(1, &format[i], 1);
			i += 2;
		}
		else if (format[i] == '%')
		{
			ft_treat_flag(arg, &format[i + 1], &total_return);
			i += 2;
		}
		else
		{
			total_return += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (total_return);
}

// #include <limits.h>

// int	main(void)
// {
// 	int res1 = 0;
// 	int res2 = 0;
// 	int x = 0;

	

// 	res1 = printf("%X", x);
// 	printf("\n------------------------------------\n");
// 	res2 = ft_printf("%X",x);

// printf("\nretour printf = %d\nretour ft_printf = %d\n",res1,res2);
// }