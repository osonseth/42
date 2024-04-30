/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:00:40 by max               #+#    #+#             */
/*   Updated: 2024/04/30 10:18:24 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	destroy_image_fonts(data);
	if (data->mlx_image_asteroid != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_asteroid);
	if (data->mlx_image_space != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_space);
	if (data->mlx_image_spaceship != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_spaceship);
	if (data->mlx_image_crystal != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_crystal);
	if (data->mlx_image_alien != NULL)
		mlx_destroy_image(data->mlx_init, data->mlx_image_alien);
}

void	clear_mlx_image_sprite(t_data *data, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (data->mlx_image_sprite[i])
		{
			mlx_destroy_image(data->mlx_init, data->mlx_image_sprite[i]);
			data->mlx_image_sprite[i] = NULL;
		}
		i++;
	}
	free(data->mlx_image_sprite);
	data->mlx_image_sprite = NULL;
}

void	destroy_image_fonts(t_data *data)
{
	if (data->mlx_image_font_zero)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_zero);
	if (data->mlx_image_font_one)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_one);
	if (data->mlx_image_font_two)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_two);
	if (data->mlx_image_font_three)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_three);
	if (data->mlx_image_font_four)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_four);
	if (data->mlx_image_font_five)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_five);
	if (data->mlx_image_font_six)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_six);
	if (data->mlx_image_font_seven)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_seven);
	if (data->mlx_image_font_eight)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_eight);
	if (data->mlx_image_font_nine)
		mlx_destroy_image(data->mlx_init, data->mlx_image_font_nine);
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
