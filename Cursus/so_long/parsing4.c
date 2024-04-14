/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:32:22 by max               #+#    #+#             */
/*   Updated: 2024/04/14 02:37:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_strdup(const char *s)
{
    char *dest;

    dest = malloc(1 + ft_strlen((char *)s) * sizeof(char));
    if (!dest)
        return (NULL);
    ft_strcpy(dest, s);
    return (dest);
}
void make_duplicate_of_map(t_data *data)
{
    int i;

    data->duplicate_of_map = malloc(data->map_height * sizeof(char *));
    if (data->duplicate_of_map == NULL)
    {
        clear_array(data->map, data->map_height);
        perror("Error\nMemory allocation error");
        exit(EXIT_FAILURE);
    }
    i = 0;

    while (i < data->map_height)
    {
        data->duplicate_of_map[i] = ft_strdup(data->map[i]);
        if (data->duplicate_of_map[i] == NULL)
        {
            clear_array(data->map, data->map_height);
            clear_array(data->duplicate_of_map, i);
            perror("Error\nMemory allocation error");
            exit(EXIT_FAILURE);
        }

        i++;
    }
}
void flood_fill(t_data *data, size_t y, size_t x)
{
    if (data->duplicate_of_map[y][x] != '1')
    {
        data->duplicate_of_map[y][x] = '1';
        flood_fill(data, y, x - 1);
        flood_fill(data, y, x + 1);
        flood_fill(data, y - 1, x);
        flood_fill(data, y + 1, x);
    }
}
void check_valid_way(t_data *data)
{
    int i;
    int j;
    i = 0;

    while (i < data->map_height)
    {
        j = 0;
        while (data->duplicate_of_map[i][j])
        {
            if (data->duplicate_of_map[i][j] == 'C')

                display_error_and_clear_array(data, "Error\nImpossible to collect all collectibles");

            if (data->duplicate_of_map[i][j] == 'E')

                display_error_and_clear_array(data, "Error\nImpossible to reach exit");

            j++;
        }
        i++;
    }
}

