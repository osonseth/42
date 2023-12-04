/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:10 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/04 19:05:10 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_treat_flag(va_list arg, const char *format, int *total_return);
void	ft_flag_d(int n, int *total_return);
void	ft_flag_s(char *str, int *total_return);
void	ft_flag_c(char c, int *total_return);
void	ft_flag_u(unsigned int n, int *total_return);
void	ft_flag_X(unsigned long int n, int *total_return);
void	ft_flag_x(unsigned long int n, int *total_return);
void	ft_flag_p(unsigned long int n, int *total_return);
int		check_flag(char c);
int		check_bonus(char c);

#endif