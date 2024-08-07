/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:27 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/21 23:40:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

char *ft_strdup(char *s);
int ft_strlen(char *str);
bool is_space(char c);
bool ft_isalpha(char c);
bool ft_isdigit(char c);
bool is_alnum_or_underscore(char c);
bool is_alpha_or_underscore(char c);
int ft_strncmp(char *s1, char *s2, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
void ft_bzero(void *s, size_t n);
char **ft_split(char *str);

#endif