/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:10 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/25 22:39:24 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>

typedef struct lst
{
	int	len;
	int	total_len;

}		lst;

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_print_d(int n, lst *sc);
void	ft_print_s(char *str, lst *sc);

#endif