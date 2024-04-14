/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:22:30 by max               #+#    #+#             */
/*   Updated: 2024/04/14 07:36:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_and_window(t_data *data)
{

    data->mlx_init = mlx_init();
    if (data->mlx_init == NULL)
        display_error_and_clear_array(data, "Error\nMlx initialization failed");

    data->mlx_windows = mlx_new_window(data->mlx_init, data->map_width * 64, data->map_height * 64, "SO LONG");
    if (data->mlx_windows == NULL)
        display_error_and_clear_array(data, "Error\nMlx open window failed");
}

void open_image(t_data *data)
{
    data->mlx_image_asteroid = mlx_xpm_file_to_image(data->mlx_init, "xpm/asteroid.xpm", &(data->image_width), &(data->image_height));
    if (data->mlx_image_asteroid == NULL)
        clear_array_and_destroy_image(data);
    data->mlx_image_space = mlx_xpm_file_to_image(data->mlx_init, "xpm/space.xpm", &(data->image_width), &(data->image_height));
    if (data->mlx_image_space == NULL)
        clear_array_and_destroy_image(data);
    data->mlx_image_spaceship = mlx_xpm_file_to_image(data->mlx_init, "xpm/spaceship.xpm", &(data->image_width), &(data->image_height));
    if (data->mlx_image_spaceship == NULL)
        clear_array_and_destroy_image(data);
    data->mlx_image_astro = mlx_xpm_file_to_image(data->mlx_init, "xpm/astro.xpm", &(data->image_width), &(data->image_height));
    if (data->mlx_image_astro == NULL)
        clear_array_and_destroy_image(data);
    data->mlx_image_exit = mlx_xpm_file_to_image(data->mlx_init, "xpm/exit.xpm", &(data->image_width), &(data->image_height));
    if (data->mlx_image_exit == NULL)
        clear_array_and_destroy_image(data);
}

void display_game(t_data *data)
{
    int i = 0;
    int j;

    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width)
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_asteroid, j * 64, i * 64);
            if (data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_space, j * 64, i * 64);
            if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_astro, j * 64, i * 64);
            if (data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_spaceship, j * 64, i * 64);
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

