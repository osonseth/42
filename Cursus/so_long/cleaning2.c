/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:00:40 by max               #+#    #+#             */
/*   Updated: 2024/04/16 02:28:56 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_windows_and_display(t_data *data)
{
    if (data->mlx_windows != NULL)
        mlx_destroy_window(data->mlx_init, data->mlx_windows);
    if (data->mlx_init != NULL)
        mlx_destroy_display(data->mlx_init);

    free(data->mlx_init);
}

void destroy_image(t_data *data)
{
    if (data->mlx_image_asteroid != NULL)
        mlx_destroy_image(data->mlx_init, data->mlx_image_asteroid);
    if (data->mlx_image_space != NULL)
        mlx_destroy_image(data->mlx_init, data->mlx_image_space);
    if (data->mlx_image_spaceship != NULL)
        mlx_destroy_image(data->mlx_init, data->mlx_image_spaceship);
    if (data->mlx_image_astro != NULL)
        mlx_destroy_image(data->mlx_init, data->mlx_image_astro);
    if (data->mlx_image_exit != NULL)
        mlx_destroy_image(data->mlx_init, data->mlx_image_exit);
}

void clear_mlx_image_sprite(t_data *data, int j)
{
    int i;
    i = 0;

    while (i < j)
    {
        if (data->mlx_image_sprite[i])
        {
            mlx_destroy_image(data->mlx_init, data->mlx_image_sprite[i]);
            // free(data->mlx_image_sprite[i]);
            data->mlx_image_sprite[i] = NULL;
        }
        i++;
    }
    free(data->mlx_image_sprite);
    data->mlx_image_sprite = NULL;
}