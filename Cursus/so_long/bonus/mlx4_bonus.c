/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx4_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:34 by max               #+#    #+#             */
/*   Updated: 2024/04/20 15:02:12 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_alien_up(t_data *data)
{
	if (data->map[data->alien_y - 1][data->alien_x] == '0'
		|| data->map[data->alien_y - 1][data->alien_x] == 'P')
	{
		if (data->map[data->alien_y - 1][data->alien_x] == 'P')
			clean_all(data, "Ennemy kill you !");
		else
		{
			data->map[data->alien_y][data->alien_x] = '0';
			data->map[data->alien_y - 1][data->alien_x] = 'A';
			data->alien_y--;
		}
	}
}

void	move_alien_down(t_data *data)
{
	if (data->map[data->alien_y + 1][data->alien_x] == '0'
		|| data->map[data->alien_y + 1][data->alien_x] == 'P')
	{
		if (data->map[data->alien_y + 1][data->alien_x] == 'P')
			clean_all(data, "Ennemy kill you !");
		else
		{
			data->map[data->alien_y][data->alien_x] = '0';
			data->map[data->alien_y + 1][data->alien_x] = 'A';
			data->alien_y++;
		}
	}
}

void	move_alien_left(t_data *data)
{
	if (data->map[data->alien_y][data->alien_x - 1] == '0'
		|| data->map[data->alien_y][data->alien_x - 1] == 'P')
	{
		if (data->map[data->alien_y][data->alien_x - 1] == 'P')
			clean_all(data, "Ennemy kill you !");
		else
		{
			data->map[data->alien_y][data->alien_x] = '0';
			data->map[data->alien_y][data->alien_x - 1] = 'A';
			data->alien_x--;
		}
	}
}

void	move_alien_right(t_data *data)
{
	if (data->map[data->alien_y][data->alien_x + 1] == '0'
		|| data->map[data->alien_y][data->alien_x + 1] == 'P')
	{
		if (data->map[data->alien_y][data->alien_x + 1] == 'P')
			clean_all(data, "Ennemy kill you !");
		else
		{
			data->map[data->alien_y][data->alien_x] = '0';
			data->map[data->alien_y][data->alien_x + 1] = 'A';
			data->alien_x++;
		}
	}
}
