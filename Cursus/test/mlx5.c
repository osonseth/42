/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:55:56 by max               #+#    #+#             */
/*   Updated: 2024/04/17 19:05:20 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void movement_diagram_one(t_data *data)
{
    if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time / 10000 <= 5))
    {
        move_alien_up(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time / 10000 <= 10))
    {

        move_alien_down(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time / 10000 <= 15))
    {

        move_alien_right(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time / 10000 <= 20))
    {

        move_alien_left(data);
    }
}
void movement_diagram_two(t_data *data)
{
    if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time / 10000 <= 5))
    {
        move_alien_right(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time / 10000 <= 10))
    {

        move_alien_left(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time / 10000 <= 15))
    {

        move_alien_down(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time / 10000 <= 20))
    {

        move_alien_up(data);
    }
}
void movement_diagram_three(t_data *data)
{
    if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time / 10000 <= 5))
    {
        move_alien_down(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time / 10000 <= 10))
    {

        move_alien_right(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time / 10000 <= 15))
    {

        move_alien_left(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time / 10000 <= 20))
    {

        move_alien_up(data);
    }
}
void movement_diagram_four(t_data *data)
{
    if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time / 10000 <= 5))
    {
        move_alien_left(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time / 10000 <= 10))
    {

        move_alien_up(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time / 10000 <= 15))
    {

        move_alien_right(data);
    }
    if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time / 10000 <= 20))
    {

        move_alien_down(data);
    }
}