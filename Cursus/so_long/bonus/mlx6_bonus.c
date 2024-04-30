/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx6_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:28:52 by max               #+#    #+#             */
/*   Updated: 2024/04/30 11:29:00 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_sprite_zero_to_seven(t_data *data, int x, int y)
{
	if (data->time <= 10000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[0], x, y);
	if (data->time > 10000 && data->time <= 20000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[1], x, y);
	if (data->time > 20000 && data->time <= 30000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[2], x, y);
	if (data->time > 30000 && data->time <= 40000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[3], x, y);
	if (data->time > 40000 && data->time <= 50000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[4], x, y);
	if (data->time > 50000 && data->time <= 60000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[5], x, y);
	if (data->time > 60000 && data->time <= 70000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[6], x, y);
	if (data->time > 70000 && data->time <= 80000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[7], x, y);
}

void	display_sprite_eight_to_fiveteen(t_data *data, int x, int y)
{
	if (data->time > 70000 && data->time <= 80000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[8], x, y);
	if (data->time > 80000 && data->time <= 90000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[9], x, y);
	if (data->time > 90000 && data->time <= 100000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[10], x, y);
	if (data->time > 100000 && data->time <= 110000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[11], x, y);
	if (data->time > 110000 && data->time <= 120000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[12], x, y);
	if (data->time > 120000 && data->time <= 130000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[13], x, y);
	if (data->time > 130000 && data->time <= 140000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[14], x, y);
	if (data->time > 150000 && data->time <= 160000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[15], x, y);
}

void	display_movement_count(t_data *data)
{
	int (i) = 0;
	data->str_count_move = ft_itoa(data, data->count_move);
	while (data->str_count_move[i])
	{
		display_movement_count_split(data, i);
		if (data->str_count_move[i] == '5')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_font_five, i * 64, data->map_height * 64);
		if (data->str_count_move[i] == '6')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_font_six, i * 64, data->map_height * 64);
		if (data->str_count_move[i] == '7')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_font_seven, i * 64, data->map_height * 64);
		if (data->str_count_move[i] == '8')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_font_eight, i * 64, data->map_height * 64);
		if (data->str_count_move[i] == '9')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_font_nine, i * 64, data->map_height * 64);
		i++;
	}
	free(data->str_count_move);
	data->str_count_move = NULL;
}

void	display_movement_count_split(t_data *data, int i)
{
	if (data->str_count_move[i] == '0')
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_font_zero, i * 64, data->map_height * 64);
	if (data->str_count_move[i] == '1')
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_font_one, i * 64, data->map_height * 64);
	if (data->str_count_move[i] == '2')
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_font_two, i * 64, data->map_height * 64);
	if (data->str_count_move[i] == '3')
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_font_three, i * 64, data->map_height * 64);
	if (data->str_count_move[i] == '4')
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_font_four, i * 64, data->map_height * 64);
}

void	open_font_split(t_data *data)
{
	data->mlx_image_font_zero = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/00.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_zero == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_one = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/01.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_one == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_two = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/02.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_two == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_three = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/03.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_three == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_four = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/04.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_four == NULL)
		clean_all(data, "Error\nMlx open image failed");
}
