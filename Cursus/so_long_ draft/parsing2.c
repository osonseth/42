/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:38:02 by max               #+#    #+#             */
/*   Updated: 2024/04/09 22:55:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strncmp(char *s1, char *s2, int n)
{
    if (n == 0)
        return (0);
    while (*s1 && n - 1 > 0)
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        s1++;
        s2++;
        n--;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

// calcul la longueur d'une lignes de la map
int ft_strlen_so_long(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
    {
        i++;
    }
    return (i);
}
// fonction qui check que le fichier (map) finisse bien par .ber
void check_argument(char *argument)
{
    int i;

    i = 0;

    while (argument[i])
        i++;

    if (ft_strncmp(".ber", &argument[i - 4], 4))
    {
        printf("Error\ninvalid name of map\n");
        exit(EXIT_FAILURE);
    }
}
// fonction qui clean le double de la map 
void clear_double_map(t_data *data)
{
	unsigned int i;
	i = 0;

	while (i < data->number_of_line)
	{
		if (data->double_map[i])
			free(data->double_map[i]);
		else
		{
			free(data->double_map);
			break;
		}
		i++;
	}
	free(data->double_map);
}
// fonction qui crée un double de la map 
void make_double_map(t_data *data)
{
    
    unsigned int i;
    i = 0;

    data->double_map = malloc(data->number_of_line * sizeof(char *));
    if (data->double_map == NULL)
    {
        clear_map(data);
        exit(EXIT_FAILURE);
    }

    while (i < data->number_of_line)
    {
        data->double_map[i] = ft_strdup(data->map[i]);

        if (data->double_map[i] == NULL)
        {
            clear_map(data);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
	while (i < data->number_of_line)

	{
		printf("%s", data->double_map[i]);
		i++;
	}
    clear_double_map(data);
}
