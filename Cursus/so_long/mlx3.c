/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:03:00 by max               #+#    #+#             */
/*   Updated: 2024/04/16 01:34:13 by max              ###   ########.fr       */
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
        if (data->sprite[i] == NULL)
            clear_array_and_array_of_sprite(data, i);
        i++;
    }
}
