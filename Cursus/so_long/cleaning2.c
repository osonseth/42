/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:00:40 by max               #+#    #+#             */
/*   Updated: 2024/04/30 16:14:09 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_windows_and_display(t_data *data)
{
	if (data->mlx_windows != NULL)
		mlx_destroy_window(data->mlx_init, data->mlx_windows);
	if (data->mlx_init != NULL)
		mlx_destroy_display(data->mlx_init);
	free(data->mlx_init);
}

void	destroy_image(t_data *data)
{
	if (data->mlx_image_asteroid != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_asteroid);
	if (data->mlx_image_space != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_space);
	if (data->mlx_image_spaceship != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_spaceship);
	if (data->mlx_image_crystal != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_crystal);
	if (data->mlx_image_exit != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_exit);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
