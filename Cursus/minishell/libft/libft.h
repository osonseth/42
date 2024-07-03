/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:27 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/03 22:53:17 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdbool.h>
#include <stdlib.h>

char *ft_strdup(char *s);
char *ft_strdup_simple_cmd(char *s);
int ft_strlen_simple_cmd(char *str);
int ft_strlen(char *str);
bool ft_isalpha(char c);
bool ft_isdigit(char c);
bool is_alnum_or_underscore(char c);
bool is_alpha_or_underscore(char c);
int ft_strncmp(char *s1, char *s2, size_t n);

#endif