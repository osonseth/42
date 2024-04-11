/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:53:40 by max               #+#    #+#             */
/*   Updated: 2024/04/11 19:27:26 by max              ###   ########.fr       */
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
        if (length < data->number_of_map_lines)
        {
            clear_array(data->map, data->number_of_map_lines);
            display_error("Error\nThe map is not a rectangle");
        }
    }
}
