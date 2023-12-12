/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:04:36 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/12 19:57:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void	ft_treat_bonus(va_list arg, const char *format, int *i,
		int *total_return)
{
	bool(dieze) = false;
	bool(space) = false;
	bool(plus) = false;
	va_list (arg_copy);
	va_copy (arg_copy, arg);

	while (check_bonus(*format))
	{
		if (*format == '#')
			dieze = true;
		if (*format == ' ')
			space = true;
		if (*format == '+')
			plus = true;
		(*i)++;
		format++;
	}
	if (space == true && plus == true)
	space = false;
	if (*format == 'x' && dieze == true)
	{
		ft_flag_dieze_and_x(va_arg(arg, unsigned long), total_return);
		return ;
	}
	else if (*format == 'X' && dieze == true)
	{
		ft_flag_dieze_and_bigx(va_arg(arg, unsigned long), total_return);
		return ;
	}	
	else if ((*format == 'd' || *format == 'i') && space == true)
		ft_flag_di_and_space(va_arg(arg, int), total_return);
	else if ((*format == 'd' || *format == 'i') && plus == true)
		ft_flag_di_and_plus(va_arg(arg, int), total_return);
	else
		ft_treat_flag(arg, format, total_return);
}



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
		ft_flag_bigx(va_arg(arg, unsigned long int), total_return);
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
			ft_treat_bonus(arg, &format[i], &i, &total_return);
			i++;
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
// 	char x = 'a';
// 	char y = '\0';
// 	char z = '1';
	
//    Expected: [+0], return: 2
//         Got:      [ 0], return: 2
//      You can rerun this test with sh test 1113
//      The function was called like this:
//    ft_printf("%+d", 0);


	


// 	res1 = printf("%c%c%c*\n", x,y,z);
// 	printf("\n------------------------------------\n");
// 	res2 = ft_printf("%c%c%c*\n", x,y,z);

// printf("\n------------------------------------\n");
// 	printf("\nretour printf = %d\nretour ft_printf = %d\n", res1, res2);
// }