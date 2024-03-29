/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:31 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/27 21:49:12 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_data
{
	int fd;
	unsigned int number_of_line;
	char **map;

} t_data;

typedef struct s_list
{
	char *line_of_map;
	struct s_list *next;
} t_list;

void error(t_list *map);
void check_first_wall(t_list *map);
void check_middles_wall(t_list *map);
void check_last_wall(t_list *map);
bool list_is_empty(t_list *list);
int list_length(t_list *list);
void print_list(t_list *list);
t_list *make_list(t_data *data, t_list *map);
t_list *insert_back_list(t_list *list, char *line);
t_list *cut_front_list(t_list *map);
t_list *cut_back_list(t_list *map);
t_list *remove_front_list(t_list *list);
t_list *clear_list(t_list *list);
t_list *manage(t_data *data, t_list *map);
void check_map_is_rectangle(t_list *map);
void display_error(char *str);
int ft_strlen(char *str);
void ft_strcpy(char *dst, char *src);
char *ft_strdup(char *s);
void clear_map(t_data *data);

#endif