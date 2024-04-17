/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:15:57 by max               #+#    #+#             */
/*   Updated: 2024/04/17 13:07:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void keypress_is_up(t_data *data)
{

    if (data->map[data->player_y - 1][data->player_x] == '0')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y - 1][data->player_x] = 'P';
        data->player_y = data->player_y - 1;
    }
    else if (data->map[data->player_y - 1][data->player_x] == 'C')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y - 1][data->player_x] = 'P';
        data->player_y = data->player_y - 1;
    }
    else if (data->map[data->player_y - 1][data->player_x] == 'E')
        clean_all(data, "END OF THE GAME !");
    else
        return;
}
void keypress_is_down(t_data *data)
{
    if (data->map[data->player_y + 1][data->player_x] == '0')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y + 1][data->player_x] = 'P';
        data->player_y = data->player_y + 1;
    }
    else if (data->map[data->player_y + 1][data->player_x] == 'C')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y + 1][data->player_x] = 'P';
        data->player_y = data->player_y + 1;
    }
    else if (data->map[data->player_y + 1][data->player_x] == 'E')
        clean_all(data, "END OF THE GAME !");
    else
        return;
}
void keypress_is_right(t_data *data)
{
    if (data->map[data->player_y][data->player_x + 1] == '0')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y][data->player_x + 1] = 'P';
        data->player_x = data->player_x + 1;
    }
    else if (data->map[data->player_y][data->player_x + 1] == 'C')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y][data->player_x + 1] = 'P';
        data->player_x = data->player_x + 1;
    }
    else if (data->map[data->player_y][data->player_x + 1] == 'E')
        clean_all(data, "END OF THE GAME !");
    else
        return;
}
void keypress_is_left(t_data *data)
{
    if (data->map[data->player_y][data->player_x - 1] == '0')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y][data->player_x - 1] = 'P';
        data->player_x = data->player_x - 1;
    }
    else if (data->map[data->player_y][data->player_x - 1] == 'C')
    {
        data->map[data->player_y][data->player_x] = '0';
        data->map[data->player_y][data->player_x - 1] = 'P';
        data->player_x = data->player_x - 1;
    }
    else if (data->map[data->player_y][data->player_x - 1] == 'E')
        clean_all(data, "END OF THE GAME !");
    else
        return;
}