/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:03:19 by max               #+#    #+#             */
/*   Updated: 2024/04/11 02:00:30 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parsing_management(t_data *data)
{
	char *map_in_string;
	check_map_name(data->map_name);
	map_in_string = read_map(data->map_name);
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
