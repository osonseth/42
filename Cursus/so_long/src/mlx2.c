/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:15:57 by max               #+#    #+#             */
/*   Updated: 2024/04/20 16:46:21 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keypress_is_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == '0')
	{
		update_data(data, 1);
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
	{
		update_data(data, 1);
		data->number_of_collectibles--;
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
		display_movement_count(data);
	}
	else
		return ;
}

void	keypress_is_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == '0')
	{
		update_data(data, 2);
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'C')
	{
		update_data(data, 2);
		data->number_of_collectibles--;
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
		display_movement_count(data);
	}
	else
		return ;
}

void	keypress_is_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '0')
	{
		update_data(data, 3);
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'C')
	{
		update_data(data, 3);
		data->number_of_collectibles--;
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
		display_movement_count(data);
	}
	else
		return ;
}

void	keypress_is_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == '0')
	{
		update_data(data, 4);
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'C')
	{
		update_data(data, 4);
		data->number_of_collectibles--;
		data->count_move++;
		display_movement_count(data);
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
		display_movement_count(data);
	}
	else
		return ;
}

int	close_windows(t_data *data)
{
	clean_all(data, "You left the game !");
	return (0);
}
