/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:52:07 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/03 09:49:09 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* fonctions pour le parsing*/

void check_first_wall(t_list *map)
{

	int i;
	i = 0;

	while (map->line_of_map[i])
	{
		if (map->line_of_map[i] != '1' && map->line_of_map[i] != '\n')
			error(map);
		i++;
	}
}

void check_middles_wall(t_list *map)
{
	t_list *temp;
	temp = map->next;
	int len;
	len = ft_strlen_so_long(temp->line_of_map);

	while (temp->next != NULL)
	{
		if (temp->line_of_map[0] != '1' || temp->line_of_map[len - 1] != '1')
			error(map);
		temp = temp->next;
	}
}

void check_last_wall(t_list *map)
{
	int i;
	i = 0;
	t_list *temp;
	temp = map;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	while (temp->line_of_map[i])
	{
		if (temp->line_of_map[i] != '1')
			error(map);
		i++;
	}
}

/* check que toutes les lignes fassent la meme longueur et que la longeur soit
 supérieur a la largeur*/
void check_map_is_rectangle(t_list *map)
{
	int width;
	int length;

	t_list *temp;
	temp = map;

	length = 0;
	width = list_length(map);
	while (temp != NULL)
	{
		length += ft_strlen_so_long(temp->line_of_map);
		temp = temp->next;
	}
	if (length == 0 && width == 0)
		error(map);
	else if (length % width != 0)
		error(map);
	else
	{
		length /= width;
		if (length < width)
			error(map);
	}
}
void error(t_list *map)
{
	printf("Error\ninvalid map\n");
	clear_list(map);
	exit(EXIT_FAILURE);
}
