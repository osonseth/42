/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/19 22:35:04 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/* void	ft_arg(char c)
{
	va_list	arg;
	lst		sc;

} */

/* int	trait_flag(char **format,va_list *arg,lst *sc)
{
	
} */
int	ft_printf(const char *format, ...)
{
	va_list	arg;
	lst		sc;

	va_start(arg, format);
	sc.len = 0;
	sc.total_len = 0;
	while (*format)
	{
		if (*format == '%' && (*(format + 1)) == 'd')
		{
			ft_print_d(va_arg(arg, int),&sc);
			format ++;
		}
		// write(1, ft_itoa(va_arg(arg,int)),5);
		format++;
		sc.total_len += write(1, format, 1);
		
	}
	printf("\n%d\n",sc.len);
	va_end(arg);
	return (sc.len);
}

#include <stdio.h>

int	main(void)
{
	int i = INT_MIN;
	// char str[]=NULL;
	// int *p = NULL;

	// i = ft_printf("coucou\n");

	ft_printf("%d\n%d\n%d\n", i, 12345,6789);
	
	// printf("%s",str);
	// printf("%p\n",p);
	// printf("%d\n",result);
}