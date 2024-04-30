/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:15:57 by max               #+#    #+#             */
/*   Updated: 2024/04/20 14:59:17 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	keypress_is_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->player_y = data->player_y - 1;
		data->count_move++;
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->player_y = data->player_y - 1;
		data->number_of_collectibles--;
		data->count_move++;
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'A')
		clean_all(data, "Ennemy kill you !");
	else if (data->map[data->player_y - 1][data->player_x] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
	}
	else
		return ;
}

void	keypress_is_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->player_y = data->player_y + 1;
		data->count_move++;
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->player_y = data->player_y + 1;
		data->number_of_collectibles--;
		data->count_move++;
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'A')
		clean_all(data, "Ennemy kill you !");
	else if (data->map[data->player_y + 1][data->player_x] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
	}
	else
		return ;
}

void	keypress_is_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->player_x = data->player_x + 1;
		data->count_move++;
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->player_x = data->player_x + 1;
		data->number_of_collectibles--;
		data->count_move++;
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'A')
		clean_all(data, "Ennemy kill you !");
	else if (data->map[data->player_y][data->player_x + 1] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
	}
	else
		return ;
}

void	keypress_is_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->player_x = data->player_x - 1;
		data->count_move++;
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->player_x = data->player_x - 1;
		data->number_of_collectibles--;
		data->count_move++;
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'A')
		clean_all(data, "Ennemy kill you !");
	else if (data->map[data->player_y][data->player_x - 1] == 'E'
		&& data->number_of_collectibles == 0)
	{
		clean_all(data, "END OF THE GAME !");
		data->count_move++;
	}
	else
		return ;
}

int	close_windows(t_data *data)
{
	clean_all(data, "You left the game !");
	return (0);
}
