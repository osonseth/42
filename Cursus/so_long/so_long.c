/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:49:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/19 23:35:00 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_list	*map;
	char	*tmp;

	t_data(data) = {0};
	data.fd = open("map.ber", O_RDONLY);
	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(data.fd);
		if (tmp == NULL)
			break ;
		map = insert_back_list(map, tmp);
	}
	print_list(map);
	clear_list(map);
}
