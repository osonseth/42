/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:27 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/02 09:16:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdbool.h>
#include <stdlib.h>

char *ft_strdup_simple_cmp(char *s);
int ft_strlen_simple_cmd(char *str);
int ft_strlen(char *str);
bool ft_isalpha(char c);
bool ft_isdigit(char c);

#endif