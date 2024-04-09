/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/09 22:46:21 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list *parsing(t_data *data, t_list *map)
{
	check_argument(data->arg);
	map = make_list(map,data);

	check_map_is_rectangle(map);
	check_first_wall(map);
	check_last_wall(map);
	check_middles_wall(map);
	data->number_of_line = list_length(map);
	make_map(data, map);

	return (map);
}
void manage(t_data *data)
{
	t_list *map;
	map = NULL;
	map = parsing(data, map);
	clear_list(map);
	make_double_map(data);
	// unsigned int i = 0;
	// while (i < data->number_of_line)

	// {
	// 	printf("%s", data->map[i]);
	// 	i++;
	// }
	clear_map(data);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\ninvalid number of arguments\n");
		return 1;
	}
	t_data(data) = {0};
	data.arg = argv[1];

	manage(&data);
}
