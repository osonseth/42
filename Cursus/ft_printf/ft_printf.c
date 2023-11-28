/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/28 18:48:36 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	t_struct	data;

	va_list(arg);
	va_start(arg, format);
	data.total_len = 0;
	while (*format)
	{
		if (*format == '%' && (*(format + 1)) == 's')
		{
			ft_print_s(va_arg(arg, char *), &sc);
			format++;
		}
		if (*format == '%' && (*(format + 1)) == 'd')
		{
			ft_print_d(va_arg(arg, int), &sc);
			format++;
		}
		format++;
		sc.total_len += write(1, format, 1);
	}
	printf("\n%d\n", sc.total_len);
	va_end(arg);
	return (sc.len);
}

#include <stdio.h>

int	main(void)
{
	char str[] = "coucou";
	int i = INT_MIN;

	ft_printf("%s\n%d\n", str, i);

	// i = ft_printf("coucou\n");

	// ft_printf("%d\n%d\n%d\n", i, 12345,6789);

	// printf("%s",str);
	// printf("%p\n",p);
	// printf("%d\n",result);
}