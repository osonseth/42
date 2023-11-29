/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:10 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/29 00:54:18 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct sc
{
	int			total_len;
	const char	*ptr_format;

}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_treat_flag(t_struct *data, va_list arg);
void			ft_flag_d(int n, t_struct *data);
void			ft_flag_s(char *str, t_struct *data);
void			ft_flag_c(char c, t_struct *data);
void			ft_flag_u(unsigned int n, t_struct *data);
void			ft_flag_X(unsigned int n, t_struct *data);
void			ft_flag_x(unsigned int n, t_struct *data);
void			ft_flag_p(unsigned long int n, t_struct *data);

#endif