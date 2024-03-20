/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:45:01 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 15:40:59 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
