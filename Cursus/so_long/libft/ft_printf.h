/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:10 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:15 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_abs(int n);
void	ft_treat_flag(va_list arg, const char *format, int *total_return);
void	ft_treat_bonus(va_list arg, const char *format, int *i,
			int *total_return);
void	ft_flag_d(int n, int *total_return);
void	ft_flag_s(char *str, int *total_return);
void	ft_flag_c(char c, int *total_return);
void	ft_flag_u(unsigned int n, int *total_return);
void	ft_flag_bigx(unsigned long int n, int *total_return);
void	ft_flag_x(unsigned long int n, int *total_return);
void	ft_flag_p(unsigned long int n, int *total_return);
int		check_bonus(char c);
int		ft_isdigit(int c);
void	ft_putstr(char *str, int *j, int *total_return);
void	ft_flag_dieze_and_x(unsigned int n, int *total_return);
void	ft_flag_dieze_and_bigx(unsigned int n, int *total_return);
void	ft_flag_di_and_space(int n, int *total_return);
void	ft_flag_di_and_plus(int n, int *total_return);

#endif