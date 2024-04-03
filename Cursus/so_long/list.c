/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:45:01 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/03 09:34:06 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*fonctions servant a la création et manipulation de listes chainées*/

// ouvre le .ber et crée une liste dont chaque noeud contient une ligne
t_list *make_list(t_list *map,t_data *data)
{
	char *tmp;
	int fd;

	fd = open(data->arg, O_RDONLY);

	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		map = insert_back_list(map, tmp);
	}
	close(fd);
	return (map);
}

void make_map(t_data *data, t_list *map)
{
	unsigned int i;
	i = 0;
	data->map = malloc(data->number_of_line * sizeof(char *));

	if (data->map == NULL)
	{
		clear_list(map);
		exit(EXIT_FAILURE);
	}

	while (i < data->number_of_line)
	{
		data->map[i] = ft_strdup(map->line_of_map);

		if (data->map[i] == NULL)
		{
			clear_map(data);
			clear_list(map);
			exit(EXIT_FAILURE);
		}

		map = map->next;
		i++;
	}
}

void clear_map(t_data *data)
{
	unsigned int i;
	i = 0;

	while (i < data->number_of_line)
	{
		if (data->map[i])
			free(data->map[i]);
		else
		{
			free(data->map);
			break;
		}
		i++;
	}
	free(data->map);
}

void ft_strcpy(char *dst, char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char *ft_strdup(char *s)
{
	char *dest;

	dest = malloc(1 + ft_strlen(s) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}