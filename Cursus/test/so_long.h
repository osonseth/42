/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:24 by max               #+#    #+#             */
/*   Updated: 2024/04/16 05:48:59 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include "time.h"
// #include "X11/keysym.h"

#define UP 122
#define LEFT 113
#define DOWN 115
#define RIGHT 100

typedef struct s_data
{
    bool split_new_words;
    int count_words;
    int map_height;
    int map_width;
    int image_height;
    int image_width;
    char *map_name;
    char **map;
    char **sprite;
    char **duplicate_of_map;
    size_t player_x;
    size_t player_y;
    size_t number_of_collectibles;
    size_t number_of_players;
    size_t number_of_exits;
    void *mlx_init;
    void *mlx_windows;
    void *mlx_image_asteroid;
    void *mlx_image_space;
    void *mlx_image_astro;
    void *mlx_image_spaceship;
    void **mlx_image_sprite;
    void *mlx_image_exit;

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
void clear_array(char ***array, int i);
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
void game_management(t_data *data);
void init_and_window(t_data *data);
void open_image(t_data *data);
void clear_array_and_destroy(t_data *data, char *str);
void destroy_windows_and_display(t_data *data);
void destroy_image(t_data *data);
int display_game(t_data *data);
int keypress(int keycode, t_data *data);
void keypress_is_up(t_data *data);
void keypress_is_down(t_data *data);
void keypress_is_right(t_data *data);
void keypress_is_left(t_data *data);
void clear_array_and_array_of_sprite(t_data *data, int j);
void read_sprite(t_data *data);
void clear_mlx_image_sprite(t_data *dat, int j);
void display_sprite(t_data *data);

#endif