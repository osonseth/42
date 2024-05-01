/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:22:30 by max               #+#    #+#             */
/*   Updated: 2024/04/30 22:04:43 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_and_window(t_data *data)
{
	int	sizex;
	int	sizey;

	data->mlx_init = mlx_init();
	if (data->mlx_init == NULL)
		display_error_and_clear_array(data, "Error\nMlx initialization failed");
	mlx_get_screen_size(data->mlx_init, &sizex, &sizey);
	if (data->map_width > sizex || data->map_height > sizey)
		clean_all(data, "Error\nInvalid size of windows");
	data->mlx_windows = mlx_new_window(data->mlx_init, data->map_width * 64,
			(data->map_height * 64), "SO LONG");
	if (data->mlx_windows == NULL)
		display_error_and_clear_array(data, "Error\nMlx open window failed");
}

void	open_image(t_data *data)
{
	data->mlx_image_asteroid = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/asteroid.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_asteroid == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_space = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/space.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_space == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_spaceship = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/spaceship.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_spaceship == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_crystal = mlx_xpm_file_to_image(data->mlx_init,
			"xpm/crystals.xpm", &(data->image_width), &(data->image_height));
	if (data->mlx_image_crystal == NULL)
		clean_all(data, "Error\nMlx open image failed");
	data->mlx_image_exit = mlx_xpm_file_to_image(data->mlx_init, "xpm/exit.xpm",
			&(data->image_width), &(data->image_height));
	if (data->mlx_image_exit == NULL)
		clean_all(data, "Error\nMlx open image failed");
}

int	display_game(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		display_utils(data, i, j);
		i++;
	}
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
		clean_all(data, "You left the game !");
	return (0);
}

void	display_movement_count(t_data *data)
{
	ft_printf("number of move : %d\n", data->count_move);
}
