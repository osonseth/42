/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:24 by max               #+#    #+#             */
/*   Updated: 2024/04/12 01:35:44 by max              ###   ########.fr       */
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
    bool split_new_words;
    int number_of_map_lines;
    char *map_name;
    char **map;
    char **duplicate_of_map;
    size_t player_x;
    size_t player_y;
    size_t number_of_collectibles;
    size_t number_of_players;
    size_t number_of_exits;

} t_data;

int ft_strncmp(char *s1, char *s2, int n);
char *ft_strdup(const char *s);
void check_map_name(char *argument);
void parsing_management(t_data *data);
char *ft_strcpy(char *dest, const char *src);
char *ft_strjoin_solong(char *s1, char *s2);
char *read_map(char *map);
void *ft_calloc(size_t nmemb, size_t size);
int ft_count_words(char *str, char c);
int ft_strlen_split(char const *s, char c);
void ft_strcpy_split(char *dst, const char *src, int size);
char **ft_split(char const *s, t_data *data, char c);
void display_error(char *str);
void display_error_and_clear_array(t_data *data, char *str);
void clear_array_split(char **array, int j);
void clear_array(char **array, int i);
void check_map_constraints(t_data *data);
void check_map_is_rectangle(t_data *data);
void check_up_wall(t_data *data);
void check_middles_wall(t_data *data);
void check_down_wall(t_data *data);
void collect_map_data(t_data *data);
void check_collectibles_player_exit(t_data *data);
void make_duplicate_of_map(t_data *data);
void flood_fill(t_data *data, size_t y, size_t x);
void check_valid_way(t_data *data);

#endif