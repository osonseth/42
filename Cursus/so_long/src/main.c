/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:19 by max               #+#    #+#             */
/*   Updated: 2024/04/30 21:15:24 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_data(t_data *data, int x)
{
	if (x == 1)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->player_y = data->player_y - 1;
	}
	if (x == 2)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->player_y = data->player_y + 1;
	}
	if (x == 3)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->player_x = data->player_x + 1;
	}
	if (x == 4)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->player_x = data->player_x - 1;
	}
}

void	display_utils(t_data *data, int i, int j)
{
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
				data->mlx_image_crystal, j * 64, i * 64);
		if (data->map[i][j] == 'P')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_spaceship, j * 64, i * 64);
		if (data->map[i][j] == 'E')
			mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
				data->mlx_image_exit, j * 64, i * 64);
		j++;
	}
}

void	parsing_management(t_data *data)
{
	char	*map_in_string;

	check_map_name(data->map_name);
	map_in_string = read_map(data->map_name);
	if (map_in_string[0] == '\n' || map_in_string[gnl_strlen(map_in_string)
			- 1] == '\n')
	{
		free(map_in_string);
		display_error("Error\nInvalid map");
	}
	check_newline(map_in_string);
	data->map = ft_split(map_in_string, data, '\n');
	if (data->map == NULL)
	{
		free(map_in_string);
		clean_all(data, "Error\nMemory allocation");
	}
	free(map_in_string);
	check_map_constraints(data);
	make_duplicate_of_map(data);
	flood_fill(data, data->player_y, data->player_x);
	check_valid_way(data);
	clear_array(&(data->duplicate_of_map), data->map_height);
	data->image_height = 64;
	data->image_width = 64;
}

void	game_management(t_data *data)
{
	init_and_window(data);
	open_image(data);
	display_movement_count(data);
	mlx_loop_hook(data->mlx_init, display_game, data);
	mlx_hook(data->mlx_windows, 2, 1, keypress, data);
	mlx_hook(data->mlx_windows, 17, 0, close_windows, data);
	mlx_loop(data->mlx_init);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\ninvalid number of arguments\n");
		return (1);
	}
	t_data(data) = {0};
	data.map_name = argv[1];
	parsing_management(&data);
	game_management(&data);
}
