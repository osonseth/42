/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:22:30 by max               #+#    #+#             */
/*   Updated: 2024/04/16 19:55:29 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_sprite(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_image_sprite = malloc(20 * sizeof(void *));
	if (data->mlx_image_sprite == NULL)
		clear_array_and_destroy(data, "Error\nMlx open image failed");
	while (i < 20)
	{
		data->mlx_image_sprite[i] = mlx_xpm_file_to_image(data->mlx_init,
				data->sprite[i], &(data->image_width), &(data->image_height));
		if (data->mlx_image_sprite[i] == NULL)
		{
			clear_mlx_image_sprite(data, i);
			clear_array_and_destroy(data, "Error\nMlx open image failed");
		}
		i++;
	}
}

void	init_and_window(t_data *data)
{
	data->mlx_init = mlx_init();
	if (data->mlx_init == NULL)
		display_error_and_clear_array(data, "Error\nMlx initialization failed");
	data->mlx_windows = mlx_new_window(data->mlx_init, data->map_width * 64,
			data->map_height * 64, "SO LONG");
	if (data->mlx_windows == NULL)
		display_error_and_clear_array(data, "Error\nMlx open window failed");
}

void	open_image(t_data *data)
{
	open_sprite(data);
	data->mlx_image_asteroid = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/asteroid.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_asteroid == NULL)
		clear_array_and_destroy(data, "Error\nMlx open image failed");
	data->mlx_image_space = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/space.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_space == NULL)
		clear_array_and_destroy(data, "Error\nMlx open image failed");
	data->mlx_image_spaceship = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/spaceship.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_spaceship == NULL)
		clear_array_and_destroy(data, "Error\nMlx open image failed");
	data->mlx_image_astro = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/crystals.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_astro == NULL)
		clear_array_and_destroy(data, "Error\nMlx open image failed");
}

int	display_game(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		data->time += 3;
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
					data->mlx_image_asteroid, j * 64, i * 64);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
					data->mlx_image_space, j * 64, i * 64);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
					data->mlx_image_astro, j * 64, i * 64);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
					data->mlx_image_spaceship, j * 64, i * 64);
			if (data->map[i][j] == 'E')
				display_sprite(data, j * 64, i * 64);
			j++;
		}
		i++;
	}
	if (data->time > 200000)
		data->time = 0;
	return (0);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == UP)
		keypress_is_up(data);
	else if (keycode == DOWN)
		keypress_is_down(data);
	else if (keycode == RIGHT)
		keypress_is_right(data);
	else if (keycode == LEFT)
		keypress_is_left(data);
	else if (keycode == ESCAPE)
		clear_array_and_destroy(data, "You left the game !/n");
	return (0);
}
