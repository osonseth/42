/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 15:49:43 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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
