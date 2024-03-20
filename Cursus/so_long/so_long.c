/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 01:58:56 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage(t_data *data, t_list *map)
{
	char	*tmp;

	data->fd = open("map.ber", O_RDONLY);
	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			break ;
		map = insert_back_list(map, tmp);
	}
	data->number_of_line = list_length(map);
	printf("\n-----------------\n");
	print_list(map);
	printf("\n-----------------\n");
	while (*(map->line_of_map) == '\n')
	{
		map = remove_front_list(map);
	}
	printf("\n-----------------\n");
	print_list(map);
	printf("\n-----------------\n");
	clear_list(map);
	close(data->fd);
}

int	main(void)
{
	t_list	*map;

	map = NULL;
	t_data(data) = {0};
	manage(&data, map);
	printf("\n%d\n", data.number_of_line);
}
