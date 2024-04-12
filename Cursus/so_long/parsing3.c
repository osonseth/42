/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:53:40 by max               #+#    #+#             */
/*   Updated: 2024/04/12 00:30:02 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int addition_of_the_lines_of_the_map(t_data *data)
{
    int i;
    int j;
    int length;

    length = 0;
    i = 0;

    while (i < data->number_of_map_lines)
    {
        j = 0;
        while (data->map[i][j])
        {
            length++;
            j++;
        }
        i++;
    }
    return length;
}

void check_map_is_rectangle(t_data *data)
{

    int length;

    length = addition_of_the_lines_of_the_map(data);

       if (length % data->number_of_map_lines != 0)

    {

        clear_array(data->map, data->number_of_map_lines);
        display_error("Error\nThe map is not a rectangle");
    }
    else
    {
        length /= data->number_of_map_lines;
        // printf("%d\n",length);
        if (length < data->number_of_map_lines)
        {

            clear_array(data->map, data->number_of_map_lines);
            display_error("Error\nThe map is not a rectangle");
        }
    }
}
void check_up_wall(t_data *data)
{

    int i;
    i = 0;

    while (data->map[0][i])
    {
        if (data->map[0][i] != '1')
        {
            clear_array(data->map, data->number_of_map_lines);
            display_error("Error\nThe map is not surrounded by walls");
        }
        i++;
    }
}
void check_middles_wall(t_data *data)
{
    int len;
    int i;
    i = 1;
    len = ft_strlen(data->map[1]);

    while (i < data->number_of_map_lines - 1)
    {

        if (data->map[i][0] != '1' || data->map[i][len - 1] != '1')
        {
            clear_array(data->map, data->number_of_map_lines);
            display_error("Error\nThe map is not surrounded by walls");
        }
        i++;
    }
}
void check_down_wall(t_data *data)
{

    int i;
    i = 0;

    while (data->map[data->number_of_map_lines - 1][i])
    {
        if (data->map[data->number_of_map_lines - 1][i] != '1')
        {
            clear_array(data->map, data->number_of_map_lines);
            display_error("Error\nThe map is not surrounded by walls");
        }
        i++;
    }
}
