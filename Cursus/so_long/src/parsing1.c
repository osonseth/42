/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:01:35 by max               #+#    #+#             */
/*   Updated: 2024/04/30 10:12:32 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
		i++;
	if (ft_strncmp(".ber", &argument[i - 4], 4))
	{
		ft_printf("Error\nInvalid map name\n");
		exit(EXIT_FAILURE);
	}
}

// lis le fichier .ber ligne par ligne et le concatène dans une seule string
char	*read_map(char *map)
{
	int		fd;
	char	*tmp;
	char	*str;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening file");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		str = ft_strjoin_solong(str, tmp);
		free(tmp);
		tmp = NULL;
	}
	if (str == NULL)
		display_error("Error\nEmpty map");
	close(fd);
	return (str);
}

void	collect_map_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->number_of_collectibles++;
			if (data->map[i][j] == 'P')
			{
				data->number_of_players++;
				data->player_x = j;
				data->player_y = i;
			}
			if (data->map[i][j] == 'E')
				data->number_of_exits++;
			j++;
		}
		i++;
	}
}

void	check_collectibles_player_exit(t_data *data)
{
	if (data->number_of_exits != 1)
		display_error_and_clear_array(data, "Error\nInvalid number of exit");
	if (data->number_of_players != 1)
		display_error_and_clear_array(data, "Error\nInvalid number of player");
	if (data->number_of_collectibles < 1)
		display_error_and_clear_array(data,
			"Error\nInvalid number of collectibles");
}

void	check_map_constraints(t_data *data)
{
	check_map_is_rectangle(data);
	data->map_width = gnl_strlen(data->map[0]);
	check_map_char(data);
	check_up_wall(data);
	check_down_wall(data);
	check_middles_wall(data);
	collect_map_data(data);
	check_collectibles_player_exit(data);
	if (data->map_height > 16 || data->map_width > 30)
		display_error_and_clear_array(data, "Error\nThe map is too big");
}
