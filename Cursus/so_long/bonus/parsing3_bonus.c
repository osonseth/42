/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:53:40 by max               #+#    #+#             */
/*   Updated: 2024/04/30 10:19:27 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	addition_of_the_lines_of_the_map(t_data *data)
{
	int	i;
	int	j;
	int	length;

	length = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			length++;
			j++;
		}
		i++;
	}
	return (length);
}

void	check_map_is_rectangle(t_data *data)
{
	int	length;

	length = addition_of_the_lines_of_the_map(data);
	if (length % data->map_height != 0)
		display_error_and_clear_array(data,
			"Error\nThe map is not a rectangle");
}

void	check_up_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			display_error_and_clear_array(data,
				"Error\nThe map is not surrounded by walls");
		i++;
	}
}

void	check_middles_wall(t_data *data)
{
	int	len;
	int	i;

	i = 1;
	len = gnl_strlen(data->map[1]);
	while (i < data->map_height - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][len - 1] != '1')
			display_error_and_clear_array(data,
				"Error\nThe map is not surrounded by walls");
		i++;
	}
}

void	check_down_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[data->map_height - 1][i])
	{
		if (data->map[data->map_height - 1][i] != '1')
			display_error_and_clear_array(data,
				"Error\nThe map is not surrounded by walls");
		i++;
	}
}
