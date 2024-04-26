/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:22:30 by max               #+#    #+#             */
/*   Updated: 2024/04/26 21:42:14 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_and_window(t_data *data)
{
	int sizex;
	int sizey;

	data->mlx_init = mlx_init();
	if (data->mlx_init == NULL)
		display_error_and_clear_array(data, "Error\nMlx initialization failed");
	mlx_get_screen_size(data->mlx_init, &sizex, &sizey);
	if (data->map_width > sizex || data->map_height > sizey)
		clean_all(data, "Error\nInvalid size of windows");
	data->mlx_windows = mlx_new_window(data->mlx_init, sizex, sizey, "SO LONG");
	if (data->mlx_windows == NULL)
		display_error_and_clear_array(data, "Error\nMlx open window failed");
}

void open_image(t_data *data)
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

int display_game(t_data *data)
{
	int i;
	int j;

	i = 0;

	while (i < data->map_height)
	{
		j = 0;
		display_utils(data, i, j);
		i++;
	}
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

void display_movement_count(t_data *data)
{
	ft_printf("number of move : %d\n", data->count_move);
}

int test_display(t_data *data)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;

	data->p_down = 0;
	data->p_up = 0;
	data->p_left = 0;
	data->p_right = 0;

	printf("player x ; %d\n", data->player_x);
	printf("player y; %d\n", data->player_y);
	printf("       x ; %d\n", data->x);
	printf("       y ; %d\n", data->y);

	if (data->player_x < 14)
		data->p_left = 14 - data->player_x;
	if (data->player_y < 9)
		data->p_up = 9 - data->player_y;
	if (data->player_x > data->map_width - 15)
		data->p_right = data->map_width - 15 - data->player_x;
	if (data->player_y > data->map_height - 8)
		data->p_down = data->map_height - 8 - data->player_y;

	printf("p gauche : %d\n", data->p_left);
	printf("p droite : %d\n", data->p_right);
	printf("p haut   : %d\n", data->p_up);
	printf("p bas    : %d\n", data->p_down);

	if (data->player_x < data->x - 14)
		data->x = data->player_x;
	if (data->player_y < data->y - 9)
		data->y = data->player_y;
	if (data->player_x > data->x + 15)
		data->x = data->player_x;
	if (data->player_y > data->y - 8)
		data->x = data->player_x;

	k = data->x - 14 + data->p_left - ft_abs(data->p_right);
	l = data->y - 9 + data->p_up - ft_abs(data->p_down);

	printf("%d\n%d\n", k, l);

	while (i < 17)

	{
		j = 0;
		while (j < 30)
		{

			if (data->map[l + i][k + j] == '1')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
										data->mlx_image_asteroid, j * 64, i * 64);
			if (data->map[l + i][k + j] == '0')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
										data->mlx_image_space, j * 64, i * 64);
			if (data->map[l + i][k + j] == 'C')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
										data->mlx_image_crystal, j * 64, i * 64);
			if (data->map[l + i][k + j] == 'P')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
										data->mlx_image_spaceship, j * 64, i * 64);
			if (data->map[l + i][k + j] == 'E')
				mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
										data->mlx_image_exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return 0;
}
