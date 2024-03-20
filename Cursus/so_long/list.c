/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:45:01 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 15:48:20 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*make_list(t_data *data, t_list *map)
{
	char	*tmp;

	data->fd = open("map.ber", O_RDONLY);
	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			break ;
		map = insert_back_list(map, tmp);
	}
	close(data->fd);
	return (map);
}

t_list	*cut_front_list(t_list *map)
{
	while (*(map->line_of_map) == '\n')
	{
		map = remove_front_list(map);
	}
	return (map);
}

t_list	*remove_front_list(t_list *list)
{
	t_list	*node;

	if (list_is_empty(list))
		return (list);
	node = list->next;
	free(list->line_of_map);
	free(list);
	list = NULL;
	return (node);
}

t_list	*clear_list(t_list *list)
{
	t_list	*temp;
	t_list	*next_node;

	if (list_is_empty(list))
		return (list);
	temp = list;
	while (temp != NULL)
	{
		next_node = temp->next;
		free(temp->line_of_map);
		free(temp);
		temp = next_node;
	}
	return (NULL);
}
