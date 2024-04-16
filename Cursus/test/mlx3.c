/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:03:00 by max               #+#    #+#             */
/*   Updated: 2024/04/16 19:26:06 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_sprite(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("sprite.txt", O_RDONLY);
	if (fd == -1)
		clear_array_and_destroy(data, "Error\nOpening file");
	data->sprite = malloc(20 * sizeof(char *));
	if (data->sprite == NULL)
		clear_array_and_destroy(data, "Error\nMemory allocation error");
	while (i < 20)
	{
		data->sprite[i] = get_next_line(fd);
		data->sprite[i][16] = '\0';
		if (data->sprite[i] == NULL)
			clear_array_and_array_of_sprite(data, i);
		i++;
	}
}

void	display_sprite(t_data *data, int x, int y)
{
	if (data->time <= 10000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[0], x, y);
	if (data->time > 10000 && data->time <= 20000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[1], x, y);
	if (data->time > 20000 && data->time <= 30000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[2], x, y);
	if (data->time > 30000 && data->time <= 40000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[3], x, y);
	if (data->time > 40000 && data->time <= 50000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[4], x, y);
	if (data->time > 50000 && data->time <= 60000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[5], x, y);
	if (data->time > 60000 && data->time <= 70000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[6], x, y);
	if (data->time > 70000 && data->time <= 80000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[7], x, y);
	if (data->time > 80000 && data->time <= 90000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[8], x, y);
	if (data->time > 90000 && data->time <= 100000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[9], x, y);
	if (data->time > 100000 && data->time <= 110000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[10], x, y);
	if (data->time > 110000 && data->time <= 120000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[11], x, y);
	if (data->time > 120000 && data->time <= 130000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[12], x, y);
	if (data->time > 130000 && data->time <= 140000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[13], x, y);
	if (data->time > 140000 && data->time <= 150000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[14], x, y);
	if (data->time > 150000 && data->time <= 160000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[15], x, y);
	if (data->time > 160000 && data->time <= 170000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[16], x, y);
	if (data->time > 170000 && data->time <= 180000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[17], x, y);
	if (data->time > 180000 && data->time <= 190000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[18], x, y);
	if (data->time > 190000 && data->time <= 200000)
		mlx_put_image_to_window(data->mlx_init, data->mlx_windows,
			data->mlx_image_sprite[19], x, y);
}
