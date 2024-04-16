/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:41:19 by max               #+#    #+#             */
/*   Updated: 2024/04/16 19:12:15 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_array_split(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	perror("Error\nMemory allocation error");
	exit(EXIT_FAILURE);
}

void	clear_array(char ***array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if ((*array)[i])
		{
			free((*array)[i]);
			(*array)[i] = NULL;
		}
		i++;
	}
	free(*array);
	*array = NULL;
}

void	display_error_and_clear_array(t_data *data, char *str)
{
	if (data->map != NULL)
		clear_array(&(data->map), data->map_height);
	if (data->duplicate_of_map != NULL)
		clear_array(&(data->duplicate_of_map), data->map_height);
	if (data->sprite != NULL)
		clear_array(&(data->sprite), 20);
	display_error(str);
}

void	clear_array_and_destroy(t_data *data, char *str)
{
	destroy_image(data);
	if (data->mlx_image_sprite)
		clear_mlx_image_sprite(data, 20);
	destroy_windows_and_display(data);
	display_error_and_clear_array(data, str);
}

void	clear_array_and_array_of_sprite(t_data *data, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(data->sprite[i]);
		data->sprite[i] = NULL;
		i++;
	}
	free(data->sprite);
	data->sprite = NULL;
	clear_array_and_destroy(data, "Error\nmemory allocation");
}
