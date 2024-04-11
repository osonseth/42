/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:19 by max               #+#    #+#             */
/*   Updated: 2024/04/12 01:41:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parsing_management(t_data *data)
{
	// size_t x;
	// size_t y;

	char *map_in_string;
	check_map_name(data->map_name);
	map_in_string = read_map(data->map_name);
	data->map = ft_split(map_in_string, data, '\n');
	free(map_in_string);
	check_map_constraints(data);
	make_duplicate_of_map(data);
	flood_fill(data, data->player_y, data->player_x);
	check_valid_way(data);
	
	
	clear_array(data->map, data->number_of_map_lines);
	clear_array(data->duplicate_of_map, data->number_of_map_lines);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\ninvalid number of arguments\n");
		return 1;
	}

	t_data(data) = {0};
	data.map_name = argv[1];
	parsing_management(&data);
}
