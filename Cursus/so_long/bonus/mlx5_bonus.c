/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx5_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:55:56 by max               #+#    #+#             */
/*   Updated: 2024/04/20 17:17:51 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movement_diagram_one(t_data *data)
{
	if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time
			/ 10000 <= 5))
	{
		move_alien_up(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time
			/ 10000 <= 10))
	{
		move_alien_down(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time
			/ 10000 <= 15))
	{
		move_alien_right(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time
			/ 10000 <= 20))
	{
		move_alien_left(data);
	}
}

void	movement_diagram_two(t_data *data)
{
	if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time
			/ 10000 <= 5))
	{
		move_alien_right(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time
			/ 10000 <= 10))
	{
		move_alien_left(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time
			/ 10000 <= 15))
	{
		move_alien_down(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time
			/ 10000 <= 20))
	{
		move_alien_up(data);
	}
}

void	movement_diagram_three(t_data *data)
{
	if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time
			/ 10000 <= 5))
	{
		move_alien_down(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time
			/ 10000 <= 10))
	{
		move_alien_right(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time
			/ 10000 <= 15))
	{
		move_alien_left(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time
			/ 10000 <= 20))
	{
		move_alien_up(data);
	}
}

void	movement_diagram_four(t_data *data)
{
	if (data->time % 10000 == 0 && (data->time / 10000 >= 1 && data->time
			/ 10000 <= 5))
	{
		move_alien_left(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 5 && data->time
			/ 10000 <= 10))
	{
		move_alien_up(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 10 && data->time
			/ 10000 <= 15))
	{
		move_alien_right(data);
	}
	if (data->time % 10000 == 0 && (data->time / 10000 > 15 && data->time
			/ 10000 <= 20))
	{
		move_alien_down(data);
	}
}

void	check_map_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'P' && data->map[i][j] != 'A')
			{
				clean_all(data, "Error\nInvalid map");
			}
			j++;
		}
		i++;
	}
}
