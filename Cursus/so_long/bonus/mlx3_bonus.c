/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:03:00 by max               #+#    #+#             */
/*   Updated: 2024/04/30 09:16:33 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_alien(t_data *data)
{
	if (data->movement_diagram > 3)
		data->movement_diagram = 0;
	if (data->movement_diagram == 0)
		movement_diagram_one(data);
	else if (data->movement_diagram == 1)
		movement_diagram_two(data);
	else if (data->movement_diagram == 2)
		movement_diagram_three(data);
	else if (data->movement_diagram == 3)
		movement_diagram_four(data);
	data->movement_diagram++;
}

void	display_utils(t_data *data, int i, int j)
{
	while (j < data->map_width)
	{
		if (data->map[i][j] == '1')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_asteroid, j * 64, i * 64);
		if (data->map[i][j] == 'A')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_alien, j * 64, i * 64);
		if (data->map[i][j] == '0')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_space, j * 64, i * 64);
		if (data->map[i][j] == 'C')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_crystal, j * 64, i * 64);
		if (data->map[i][j] == 'P')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_spaceship, j * 64, i * 64);
		if (data->map[i][j] == 'E')
			display_sprite(data, j * 64, i * 64);
		j++;
	}
}

void	read_sprite(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("bonus/sprite.txt", O_RDONLY);
	if (fd == -1)
		clean_all(data, "Error\nOpening file");
	data->sprite = malloc(20 * sizeof(char *));
	if (data->sprite == NULL)
		clean_all(data, "Error\nMemory allocation error");
	while (i < 20)
	{
		data->sprite[i] = get_next_line(fd);
		data->sprite[i][16] = '\0';
		if (data->sprite[i] == NULL)
			clear_array_and_array_of_sprite(data, i);
		i++;
	}
}

void	open_fonts(t_data *data)
{
	open_font_split(data);
	data->mlx_image_font_five = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/05.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_five == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_six = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/06.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_six == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_seven = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/07.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_seven == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_font_eight = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/08.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_eight == NULL)
		clean_all(data, "Error\nMlx open image failed8");
	data->mlx_image_font_nine = mlx_xpm_file_to_image(data->mlx_init,
			"fonts/09.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_font_nine == NULL)
		clean_all(data, "Error\nMlx open image failed9");
}

void	display_sprite(t_data *data, int x, int y)
{
	if (data->time >= 0 && data->time <= 80000)
		display_sprite_zero_to_seven(data, x, y);
	if (data->time > 70000 && data->time <= 160000)
		display_sprite_eight_to_fiveteen(data, x, y);
	if (data->time > 160000 && data->time <= 170000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[16], x, y);
	if (data->time > 170000 && data->time <= 180000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[17], x, y);
	if (data->time > 180000 && data->time <= 190000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[18], x, y);
	if (data->time > 190000 && data->time <= 200000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[19], x, y);
}
