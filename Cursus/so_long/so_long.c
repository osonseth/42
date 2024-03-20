/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 15:37:08 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*make_list(t_data *data, t_list *map)
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
	close(data->fd);
	return (map);
}

t_list	*cut_front_list(t_list *map)
{
	while (*(map->line_of_map) == '\n')
	{
		map = remove_front_list(map);
	}
	return (map);
}

t_list	*manage(t_data *data, t_list *map)
{
	map = make_list(data, map);
	map = cut_front_list(map);
	map = cut_back_list(map);
	return (map);
}

int	main(void)
{
	t_list	*map;

	map = NULL;
	t_data(data) = {0};
	map = manage(&data, map);
	print_list (map);
	clear_list(map);
}
