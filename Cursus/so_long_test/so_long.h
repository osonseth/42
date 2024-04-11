/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:24 by max               #+#    #+#             */
/*   Updated: 2024/04/11 01:57:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_data
{
    int number_of_map_lines;
    char *map_name;

} t_data;

int ft_strncmp(char *s1, char *s2, int n);
void check_map_name(char *argument);
void parsing_management(t_data *data);
char *ft_strcpy(char *dest, const char *src);
char *ft_strjoin_solong(char *s1, char *s2);
char *read_map(char * map);

#endif