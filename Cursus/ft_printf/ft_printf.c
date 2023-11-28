/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/28 22:03:39 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_treat_flag(t_struct *data, va_list arg)
{
	while (*(data->ptr_format) == '%' || *(data->ptr_format) == 'd'
		|| *(data->ptr_format) == 's' || *(data->ptr_format) == 'c'
		|| *(data->ptr_format) == 'u')
	{
		if (*(data->ptr_format) == 'd')
		{
			ft_flag_d(va_arg(arg, int), data);
		}
		else if (*(data->ptr_format) == 's')
		{
			ft_flag_s(va_arg(arg, char *), data);
		}
		else if (*(data->ptr_format) == 'c')
		{
			ft_flag_c((char)va_arg(arg, int), data);
		}
		else if (*(data->ptr_format) == 'u')
		{
			ft_flag_u(va_arg(arg, unsigned int), data);
		}
		data->ptr_format++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_struct(data) = {0};
	va_list(arg);
	va_start(arg, format);
	data.ptr_format = format;
	while (*(data.ptr_format))
	{
		if (*(data.ptr_format) == '%' && *(data.ptr_format + 1) == '%')
		{
			data.total_len += write(1, "%%", 1);
			data.ptr_format +=2;
		}
		if (*(data.ptr_format) == '%' && *(data.ptr_format + 1) != '%')
		{
			ft_treat_flag(&data, arg);
		}
		data.total_len += write(1, data.ptr_format, 1);
		data.ptr_format++;
	}
	va_end(arg);
	return (data.total_len);
}

#include <limits.h>

int	main(void)
{
	int total_ft = 0;
	int total_print = 0;
	char str[] = "coucou";
	int i = INT_MIN;
	char c = 'B';
	char d = 'O';
	char e = 'S';
	unsigned int u = 4123567890;
	void *p = &str;
	void **pp = p;

	total_ft = ft_printf("%s\n%d\n%c%c%c%c\n%u\n%%%%\n", str, i, c, d, d, e, u);
	printf("%d\n", total_ft);
	printf("--------------------------------------------------------\n");
	total_print = printf("%p\n%p\n",u,pp);
	printf("%d\n", total_print);

	// i = ft_printf("coucou\n");

	// ft_printf("%d\n%d\n%d\n", i, 12345,6789);

	// printf("%s",str);
	// printf("%p\n",p);
	// printf("%d\n",result);
}