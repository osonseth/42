/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:10 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/28 18:26:47 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct sc
{
	int	len;
	int	total_len;

}		t_struct;

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_print_d(int n, lst *sc);
void	ft_print_s(char *str, lst *sc);

#endif