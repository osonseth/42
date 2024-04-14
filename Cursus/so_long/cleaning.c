/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:41:19 by max               #+#    #+#             */
/*   Updated: 2024/04/14 02:41:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clear_array_split(char **array, int j)
{
    int i;
    i = 0;

    while (i < j)
    {
        if (array[i])
            free(array[i]);
        i++;
    }
    free(array);
    array = NULL;

    perror("Error\nMemory allocation error");
    exit(EXIT_FAILURE);
}

void clear_array(char **array, int j)
{
    int i;
    i = 0;

    while (i < j)
    {
        if (array[i])
            free(array[i]);
        i++;
    }
    free(array);
    array = NULL;
}

void display_error_and_clear_array(t_data *data, char *str)
{
    if (data->map != NULL)
        clear_array(data->map, data->map_height);
    if (data->duplicate_of_map != NULL)
        clear_array(data->duplicate_of_map, data->map_height);
    display_error(str);
}
void clear_array_and_destroy_image(t_data *data)
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

    clear_array(data->map, data->map_height);
    display_error("Error\nMlx open image failed");
}
