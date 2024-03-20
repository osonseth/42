/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:52:07 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 18:18:45 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* fonctions pour le parsing*/

// calcul la longueur d'une lignes de la map
int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

/* check que toutes les lignes fassent la meme longueur et que la longeur soit
 supérieur a la largeur*/
void	check_map_is_rectangle(t_list *map)
{
	int	width;
	int	length;

	length = 0;
	width = list_length(map);
	while (map != NULL)
	{
		length += ft_strlen_so_long(map->line_of_map);
		map = map->next;
	}
	if (length == 0 && width == 0)
		display_error("Error\nmap vide");
	else if (length % width != 0)
		display_error("Error\nles lignes ne font pas toutes la meme longueur");
	else
	{
		length /= width;
		if (length <= width)
			display_error("Error\nla map n'est pas un rectangle");
	}
}
