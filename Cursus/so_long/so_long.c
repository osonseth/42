/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/14 20:33:07 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_line)
	{
		if (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = NULL;
		}
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	ft_str_len_line(char *str)
{
	int(i) = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	make_map(t_data *data)
{
	int		i;
	char	*tmp_line;

	data->map = malloc(data->count_line * sizeof(char *));
	if (data->map == NULL)
	{
		perror("Error allocating memory for data->map");
		exit(EXIT_FAILURE);
	}
	data->fd = open("map.ber", O_RDONLY);
	i = 0;
	while (i < data->count_line)
	{
		tmp_line = get_next_line(data->fd);
		if (tmp_line == NULL)
		{
			clean(data);
			perror("Error allocating memory for data->map");
			exit(EXIT_FAILURE);
		}
		data->map[i] = tmp_line;
		tmp_line = NULL;
		i++;
	}
	close(data->fd);
}

void	ft_count_line(t_data *data)
{
	char	*tmp_line;

	data->fd = open("map.ber", O_RDONLY);
	tmp_line = get_next_line(data->fd);
	free(tmp_line);
	while (tmp_line != NULL)
	{
		data->count_line++;
		tmp_line = get_next_line(data->fd);
		free(tmp_line);
	}
	close(data->fd);
}

void	open_map(t_data *data)
{
	ft_count_line(data);
	make_map(data);
}

int	main(void)
{
	int	i;

	t_data(data) = {0};
	open_map(&data);
	i = 0;
	while (i < data.count_line)
	{
		printf("%s", data.map[i]);
		i++;
	}
	clean(&data);
	return (0);
}
