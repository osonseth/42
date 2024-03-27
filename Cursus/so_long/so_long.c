/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/27 21:59:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void make_map(t_data *data, t_list *map)
{
	unsigned int i;
	i = 0;
	data->map = malloc(data->number_of_line * sizeof(char *));

	if (data->map == NULL)
	{
		clear_list(map);
		exit(EXIT_FAILURE);
	}

	while (i < data->number_of_line)
	{
		data->map[i] = ft_strdup(map->line_of_map);

		if (data->map[i] == NULL)
		{
			clear_map(data);
			clear_list(map);
			exit(EXIT_FAILURE);
		}

		map = map->next;
		i++;
	}
}

void clear_map(t_data *data)
{
	unsigned int i;
	i = 0;

	while (i < data->number_of_line)
	{
		if (data->map[i])
			free(data->map[i]);
		else
		{
			free(data->map);
			break;
		}
		i++;
	}
	free(data->map);
}

t_list *manage(t_data *data, t_list *map)
{
	map = make_list(data, map);

	check_map_is_rectangle(map);
	check_first_wall(map);
	check_last_wall(map);
	check_middles_wall(map);
	data->number_of_line = list_length(map);
	make_map(data, map);

	return (map);
}

int main(void)
{
	t_list *map;

	map = NULL;
	t_data(data) = {0};
	map = manage(&data, map);

	clear_list(map);

	unsigned int i = 0;
	while (i < data.number_of_line)

	{
		printf("%s", data.map[i]);
		i++;
	}
	clear_map(&data);
	
}
