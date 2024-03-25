/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:46:50 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/25 14:16:42 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*fonctions servant a la création et manipulation de listes chainées*/

// Check si la liste est vide
bool list_is_empty(t_list *list)
{
	if (list == NULL)
		return (true);
	return (false);
}

// calcul le nombre de noeuds de la chaine
int list_length(t_list *list)
{
	int size;

	size = 0;
	if (!list_is_empty(list))
	{
		while (list != NULL)
		{
			size++;
			list = list->next;
		}
	}
	return (size);
}

// affiche le contenu de la liste

void print_list(t_list *list)
{
	if (list_is_empty(list))
	{
		printf("La liste est vide\n");
		return;
	}
	while (list != NULL)
	{
		printf("%s", list->line_of_map);
		list = list->next;
	}
}

// rajoute un elément a la fin de la liste
t_list *insert_back_list(t_list *list, char *line)
{
	t_list *node;
	t_list *tmp;

	node = malloc(sizeof(*node));
	if (node == NULL)
	{
		clear_list(list);
		perror("Error allocating memory for node");
		exit(EXIT_FAILURE);
	}
	node->line_of_map = line;
	node->next = NULL;
	if (list_is_empty(list))
		return (node);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	return (list);
}

