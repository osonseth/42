/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/25 14:43:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list *manage(t_data *data, t_list *map)
{
	map = make_list(data, map);

	check_map_is_rectangle(map);
	check_first_wall(map);
	check_last_wall(map);
	check_middles_wall(map);

	return (map);
}

int main(void)
{
	t_list *map;

	map = NULL;
	t_data(data) = {0};
	map = manage(&data, map);
	print_list(map);
	clear_list(map);
}
