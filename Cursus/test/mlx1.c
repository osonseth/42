/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:22:30 by max               #+#    #+#             */
/*   Updated: 2024/04/17 19:22:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void open_sprite(t_data *data)
{
	int i;

	i = 0;
	data->mlx_image_sprite = malloc(20 * sizeof(void *));
	if (data->mlx_image_sprite == NULL)
		clean_all(data, "Error\nMlx open image failed");
	while (i < 20)
	{
		data->mlx_image_sprite[i] = mlx_xpm_file_to_image(data->mlx_init,
														  data->sprite[i], &(data->image_width), &(data->image_height));
		if (data->mlx_image_sprite[i] == NULL)
		{
			clear_mlx_image_sprite(data, i);
			clean_all(data, "Error\nMlx open image failed");
		}
		i++;
	}
}

void init_and_window(t_data *data)
{
	data->mlx_init = mlx_init();
	if (data->mlx_init == NULL)
		display_error_and_clear_array(data, "Error\nMlx initialization failed");
	data->mlx_windows = mlx_new_window(data->mlx_init, data->map_width * 64,
									   (data->map_height * 64) + 64, "SO LONG");
	if (data->mlx_windows == NULL)
		display_error_and_clear_array(data, "Error\nMlx open window failed");
}

void open_image(t_data *data)
{
	open_sprite(data);
	data->mlx_image_alien = mlx_xpm_file_to_image(data->mlx_init, "xpm/alien.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_alien == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_asteroid = mlx_xpm_file_to_image(data->mlx_init, "xpm/asteroid.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_asteroid == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_space = mlx_xpm_file_to_image(data->mlx_init, "xpm/space.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_space == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_spaceship = mlx_xpm_file_to_image(data->mlx_init, "xpm/spaceship.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_spaceship == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_astro = mlx_xpm_file_to_image(data->mlx_init, "xpm/crystals.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_astro == NULL)
		clean_all(data, "Error\nMlx open image failed");
}

int display_game(t_data *data)
{
	int i;
	int j;

	data->time += 500;
	i = 0;

	while (i < data->map_height)
	{
		j = 0;
		display_utils(data, i, j);
		i++;
	}
	move_alien(data);

	if (data->time > 200000)
		data->time = 0;
	return (0);
}

int keypress(int keycode, t_data *data)
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
		clean_all(data, "You left the game !");
	return (0);
}
