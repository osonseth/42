/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:03:00 by max               #+#    #+#             */
/*   Updated: 2024/04/16 06:58:35 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_sprite(t_data *data)
{
    
    int i;
    int fd;
    i = 0;

    fd = open("sprite.txt", O_RDONLY);
    if (fd == -1)
        clear_array_and_destroy(data, "Error\nOpening file");
    data->sprite = malloc(20 * sizeof(char *));
    if (data->sprite == NULL)
        clear_array_and_destroy(data, "Error\nMemory allocation error");
    while (i < 20)
    {
        data->sprite[i] = get_next_line(fd);
        data->sprite[i][16] = '\0';
        if (data->sprite[i] == NULL)
            clear_array_and_array_of_sprite(data, i);

        i++;
    }
}

void display_sprite(t_data *data)
{
   
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[0], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[1], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[2], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[3], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[4], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[5], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[6], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[7], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[8], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[9], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[10], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[11], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[12], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[13], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[14], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[15], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[16], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[17], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[18], 64, 64);
    usleep(750);
    mlx_put_image_to_window(data->mlx_init, data->mlx_windows, data->mlx_image_sprite[19], 64, 64);
    usleep(750);
}
